import cv2
import mediapipe as mp
import numpy as np

# Инициализация MediaPipe для распознавания рук
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(max_num_hands=1, min_detection_confidence=0.7, min_tracking_confidence=0.7)
mp_draw = mp.solutions.drawing_utils

# Захват видео с веб-камеры
cap = cv2.VideoCapture(0)

canvas = None
prev_x, prev_y = 0, 0

# Настройка размера ластика
eraser_size = 50 

while cap.isOpened():
    success, frame = cap.read()
    if not success:
        print("Не удалось получить кадр с веб-камеры.")
        break

    # Отзеркаливаем изображение
    frame = cv2.flip(frame, 1)

    if canvas is None:
        canvas = np.zeros_like(frame)

    # Конвертируем цвета для MediaPipe
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    
    rgb_frame.flags.writeable = False 
    results = hands.process(rgb_frame)
    rgb_frame.flags.writeable = True

    # Если рука найдена
    if results.multi_hand_landmarks:
        for hand_lms in results.multi_hand_landmarks:
            h, w, c = frame.shape
            
            # Получаем координаты кончиков указательного (8) и среднего (12) пальцев
            index_tip = hand_lms.landmark[8]
            middle_tip = hand_lms.landmark[12]
            
            # Получаем координаты суставов ниже кончиков (6 и 10)
            index_pip = hand_lms.landmark[6]
            middle_pip = hand_lms.landmark[10]

            x, y = int(index_tip.x * w), int(index_tip.y * h)

            # Проверяем, подняты ли пальцы
            index_is_up = index_tip.y < index_pip.y
            middle_is_up = middle_tip.y < middle_pip.y

            # 1. РЕЖИМ ЛАСТИКА (Подняты два пальца)
            if index_is_up and middle_is_up:
                prev_x, prev_y = x, y # Постоянно обновляем координаты
                
                """ # Рисуем на холсте большой ЧЕРНЫЙ круг (цвет 0, 0, 0), это стирает рисунок
                cv2.circle(canvas, (x, y), eraser_size, (0, 0, 0), cv2.FILLED)
                
                # Рисуем на самом видео БЕЛЫЙ контур, чтобы видеть область стирания
                cv2.circle(frame, (x, y), eraser_size, (255, 255, 255), 2) """

            # 2. РЕЖИМ РИСОВАНИЯ (Поднят только указательный палец)
            elif index_is_up and not middle_is_up:
                if prev_x == 0 and prev_y == 0:
                    prev_x, prev_y = x, y

                # Рисуем КРАСНУЮ линию на холсте
                cv2.line(canvas, (prev_x, prev_y), (x, y), (0, 0, 255), 10)
                prev_x, prev_y = x, y

            # Рисуем скелет руки (по желанию можно закомментировать)
            mp_draw.draw_landmarks(frame, hand_lms, mp_hands.HAND_CONNECTIONS)

    else:
        # Сбрасываем координаты, если рука пропала из кадра
        prev_x, prev_y = 0, 0

    # Накладываем рисунок с холста на видео
    gray_canvas = cv2.cvtColor(canvas, cv2.COLOR_BGR2GRAY)
    _, mask = cv2.threshold(gray_canvas, 10, 255, cv2.THRESH_BINARY)
    mask_inv = cv2.bitwise_not(mask)

    img_bg = cv2.bitwise_and(frame, frame, mask=mask_inv)
    img_fg = cv2.bitwise_and(canvas, canvas, mask=mask)
    result_frame = cv2.add(img_bg, img_fg)

    # Показываем результат
    cv2.imshow('Virtual Painter', result_frame)

    key = cv2.waitKey(1) & 0xFF
    if key in [ord('c'), ord('с')]: 
        canvas = np.zeros_like(frame)
    elif key in [ord('q'), ord('й')]:
        break

cap.release()
cv2.destroyAllWindows()
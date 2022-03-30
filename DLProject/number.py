import tensorflow as tf
from tensorflow import keras
from keras.models import Sequential
from tensorflow.keras.optimizers import SGD, Adam
from keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Activation, Dropout, BatchNormalization
from datetime import datetime
 
 
def get_data(folder_name):
    import os
 
    img_paths = []
    img_label = []
 
    for root_dir in os.listdir(os.path.join('handwrite__detect', folder_name)):
        if root_dir[0] != '.':
            for num in os.listdir(os.path.join('handwrite__detect', folder_name, root_dir)):
                if num[0] != '.':
                    for item in os.listdir(os.path.join('handwrite__detect', folder_name, root_dir, num)):
                        if item[0] != '.':
                            img_paths.append(os.path.join('handwrite__detect', folder_name, root_dir, num, item))
                            img_label.append(num)
 
    import pylab as plt
    import numpy as np
 
    img = []
    for i in img_paths:
        img.append(plt.imread(i))
    img = np.array(img)
    img = img[:, :, :, 0]
    img = np.expand_dims(img, axis=3)
    img = img.astype('float32')
    img /= 255
 
    img_label = np.array(img_label)
    img_label = tf.keras.utils.to_categorical(img_label)
 
    rnd = np.random.permutation(img_label.shape[0])
    img = img[rnd, :]
    img_label = img_label[rnd]
 
    img = tf.convert_to_tensor(img)
    img_label = tf.convert_to_tensor(img_label)
    return img, img_label
 
 
def train(epoch=90):
    (x_train, y_train), (x_test, y_test) = \
        (get_data('train_image')), (get_data('test_image'))
    model = Sequential()
    model.add(Conv2D(filters=16, kernel_size=(5, 5), padding='same', input_shape=(28, 28, 1)))
    model.add(Activation("relu"))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Conv2D(filters=64, kernel_size=(5, 5), padding='same'))
    model.add(BatchNormalization(momentum=0.9, epsilon=1e-6, center=True, scale=True))
    model.add(Activation("relu"))
    model.add(Dropout(0.3))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Conv2D(filters=16, kernel_size=(5, 5), padding='same'))
    model.add(BatchNormalization(momentum=0.9, epsilon=1e-6, center=True, scale=True))
    model.add(Activation("relu"))
    model.add(Dropout(0.2))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Flatten())
    model.add(Dense(units=256, activation='relu'))
    model.add(Dense(units=10, activation='softmax'))
    model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])
 
    model.fit(x_train, y_train, batch_size = 64, epochs = epoch, validation_batch_size = 64)
 
    print('\nEvaluation')
    result = model.evaluate(x_test, y_test)
    print('Evaluate Accuracy:', '%f%%' % (result[1] * 100))
    return result[1] * 100
 
 
print('Clear the log?')
cl = bool(input())
if (cl):
    log = open('log.txt', mode='w', buffering=1)
else:
    log = open('log.txt', mode='a', buffering=1)
print(f'GPU available: {str(tf.config.list_physical_devices("GPU"))}\n\n')
print(f'GPU available: {str(tf.config.list_physical_devices("GPU"))}\n\n', file=log)
"""
for j in range(5):
    acc = train()
    print(datetime.now().strftime("%Y-%m-%d %I:%M:%S %p"), file=log)
    print('Times ' + str(j) + ' :  Accuracy = ' + '%f%%' % acc + '\n', file = log)
"""
acc = train()
print(datetime.now().strftime("%Y-%m-%d %I:%M:%S %p"), file=log)
print('Accuracy = ' + '%f%%' % acc)
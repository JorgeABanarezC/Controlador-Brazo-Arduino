# Controlador-Brazo-Arduino
Este codigo es para controlar movimientos en un brazo robotico y placa arduino uno, recuerda que para tener mejor comportamiento en los servomotores
debes tener una fuente de alimentacion externa y comunicar todos lo negativos, con eso obtendras evitar temblores y mal funcionamiento en los movimientos.

Este código utiliza la biblioteca Servo de Arduino para controlar los servos del brazo robótico y la comunicación Bluetooth para recibir comandos
del dispositivo móvil.
Los pines para los servos están definidos en las primeras líneas del código y los objetos Servo se inicializan
en la función setup().
Los servos se inicializan en la posición central y se actualizan en función de los comandos recibidos a través
de Bluetooth en la función loop().
Los comandos son caracteres únicos ('b' para la base, 's' para el hombro, 'e' para el codo,
'w' para la muñeca y 'g' para el agarre) y se utilizan para controlar los servos de manera incremental. Por ejemplo, si se recibe el comando 'b',
la posición del servo de la base se incrementa en 10 grados y se actualiza.
El agarre se controla con un servo de rotación continua que gira en una dirección para cerrar el agarre

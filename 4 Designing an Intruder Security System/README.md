What my code does:

Once the code has run it will start in the armed state. While in the armed state the green LED will flash quickly for 100ms with 3s inbetween the flashes.
Because we did not receive sensors yet in class, I will be imitating the sensor with the 2.3 button.
If the 2.3 button is pressed and held down, the code will transition into the warning state.
In the warning state the green LED turns off and the red LED begins to blink every second (500ms on and off). If the button is held down for a total of 10s in the warning state the code will enter the alarm state. During the warning state, if the button is let go at all the code will return to the armed state and the 10s timer will be reset.
In the alarm state the red LED stays on forever, the only way to exit this state is by pressing the 4.1 button which will send the code back to the beggining in the armed state.

Issue with the code that I would like to fix:

An issue my code is having currently is that if the 2.3 button is pressed while any of the delays from the blinking LEDs is happening, the button input will not register until the delay is over.
I beleive this can be fixed by using inetrupts instead of polling but I do not fully understand interupts yet and was more comftorable with polling so this is the best I could do.

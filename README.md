# LEDCub# LEDCube

4x4x4 LED Cube with two 74HC595 shift registers.

## Component List
- Arduino UNO
- 2x 74HC595
- 64x LED's
- 16x 330Ω resistor
- 4x 4k6Ω resistor
- 4x 2N2222A transistor
- 3x tactile button (optional)

## PCB Design
![alt text](https://user-images.githubusercontent.com/43173874/106970841-07bf0000-674e-11eb-86b1-68d0efc9d171.png)

You can produce the exact same PCB by downloading the Gerber file from this GitHub Repo.

## Usage

In the main loop you can play the animations by calling the different functions. All animations have two arguments:

- Direction (MSB, LSB)
- Last state played (YES, NO)



```c++
void loop(){
    upAndDownAnimation(MSB, YES);
}
```

### Direction
Animation | MSB | LSB 
--- | --- | --- 
Up and Down* | Up | Down 
Left and Right* | Right | Left
Forward and Backward* | Backward | Forward
Circle | Clockwise | Counter Clockwise
\*This animation goes both ways in one cycle, the parameter decides the first direction.

### Last state played
In order to make the animations look smoother you can decide if you would like to play the last state of an animation. To prevent a delay when an animation is played multiple times you can implement the following code:

```c++
void loop(){
    leftAndRightAnimation(MSB, NO);
    leftAndRightAnimation(MSB, NO);
    leftAndRightAnimation(MSB, YES);
    forwardAndBackwardAnimation(LSB, NO);
    forwardAndBackwardAnimation(LSB, NO);
    forwardAndBackwardAnimation(LSB, YES);
}
```

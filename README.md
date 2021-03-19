# LEDCube

4x4x4 LED Cube with two 74HC595 shift registers.

## Component List
- [Arduino UNO](https://nl.aliexpress.com/item/32755333373.html?spm=a2g0o.productlist.0.0.dbc14623QTb3xX&algo_pvid=9b2f7433-c658-41c2-8deb-8300f2018b21&algo_expid=9b2f7433-c658-41c2-8deb-8300f2018b21-0&btsid=0b0a0ae216161130499412980eec61&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
- 2x [74HC595](https://nl.aliexpress.com/item/32522127404.html?spm=a2g0o.productlist.0.0.23446abfQ6j3nR&algo_pvid=0da9fba3-3186-4ac2-8388-dea36756f82c&algo_expid=0da9fba3-3186-4ac2-8388-dea36756f82c-0&btsid=0b0a0ae216161130830663277eec61&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
- 64x  [LED's](https://nl.aliexpress.com/item/1206472153.html?spm=a2g0o.productlist.0.0.4009241eGJ5yA4&algo_pvid=e4545c29-52de-42e0-8b29-5823c83ceebc&algo_expid=e4545c29-52de-42e0-8b29-5823c83ceebc-0&btsid=0b0a0ae216161131206573540eec61&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
- 16x [330Ω resistor](https://nl.aliexpress.com/item/1005001437008358.html?spm=a2g0o.productlist.0.0.4d8d6d8bx1iyvF&algo_pvid=c335afe7-b97a-458d-a662-6987935ea280&algo_expid=c335afe7-b97a-458d-a662-6987935ea280-1&btsid=0b0a0ae216161131453473884eec61&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
- 4x [4k6Ω resistor](https://nl.aliexpress.com/item/1005001437008358.html?spm=a2g0o.productlist.0.0.4d8d6d8bx1iyvF&algo_pvid=c335afe7-b97a-458d-a662-6987935ea280&algo_expid=c335afe7-b97a-458d-a662-6987935ea280-1&btsid=0b0a0ae216161131453473884eec61&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
- 4x [2N2222A transistor](https://nl.aliexpress.com/item/4001071895960.html?spm=a2g0o.productlist.0.0.6d173068seXlDO&algo_pvid=0b83b6fe-546d-4745-9cdd-0218ff3f3b29&algo_expid=0b83b6fe-546d-4745-9cdd-0218ff3f3b29-1&btsid=0b0a0ae216161131749454029eec61&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
- 3x [Tactile button](https://nl.aliexpress.com/item/33055922258.html?spm=a2g0o.productlist.0.0.77cf1966mUMIDd&algo_pvid=577988c5-8d7a-4b9b-8de9-b10237235511&algo_expid=577988c5-8d7a-4b9b-8de9-b10237235511-29&btsid=0b0a0ae216161132603874489eec61&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_) (optional)

## PCB Design
![alt text](https://user-images.githubusercontent.com/43173874/106970841-07bf0000-674e-11eb-86b1-68d0efc9d171.png)

You can produce the exact same PCB by downloading the Gerber file from this GitHub Repo.

## Config file
In the config file you will be able to change the input/output pins and the delay. When using the given PCB design you won't have to change the pins.

**!! Important: Don't change the helper variables !!**


## Usage

In the function **playAnimations()** you can play the animations by calling the different functions. All animations have two arguments:

- Direction (MSB, LSB)
- Last state played (YES, NO)



```c++
void playAnimations(){
  /*
  * Function: playAnimations
  * ----------------------------
  *   Plays a list of animations
  *   
  *   returns: none
  */
  playing = true;

  /*
  * Add list of animations below
  * ⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄
  */
  
  leftAndRightAnimation(MSB, NO);
  leftAndRightAnimation(MSB, YES);
  forwardAndBackwardAnimation(LSB, YES);
  circleAnimation(MSB, YES);
  upAndDownAnimation(MSB, YES);
  
  /*
  * ⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃
  * Add list of animations above
  */
  playing = false;
}

```

### Direction
Animation | MSB | LSB 
--- | --- | --- 
Up and Down* | Up | Down 
Left and Right* | Right | Left
Forward and Backward* | Backward | Forward
Circle | Clockwise | Counter Clockwise
\*This animation goes both ways in one cycle, the parameter decides the initial direction.

### Last state played
In order to make the animations look smoother you can decide if you would like to play the last state of an animation. To prevent a delay when an animation is played multiple times you can implement the following code:

```c++
void playAnimations(){
    playing = true;

    leftAndRightAnimation(MSB, NO);
    leftAndRightAnimation(MSB, NO);
    leftAndRightAnimation(MSB, YES);
    forwardAndBackwardAnimation(LSB, NO);
    forwardAndBackwardAnimation(LSB, NO);
    forwardAndBackwardAnimation(LSB, YES);

    playing = false;
}
```

## Create animations
More soon...

# SLERP
 *A simple interoplation/easing library for C*
<br/>
How to use:
```c
#define SLERP_H
#include "slerp.h" // (or whatever path you use)
```
that's it!


All easing functions are avalible to view and try out at [easings.net](https://easings.net/). You can access the easings functions by using the `sl` prefex, e.g.
```c
float f = sl_easeInSine(0.5);
```
and interpolate between values using the `slerp` function
```c
float i = slerp(50, 75, sl_easeInSine(0.5)); // Interpolates somewhere between the values 50 and 75 using the easeInSine curve. In this example it would be exactly the halfway point of the interpolation curve and would output ~57.32.
```
<br/>
For perhaps more convenint usage, you can utilize the functionality of the `slerp_to` and `slerp_from` functions. Example:
```c
    slerp_t my_lerp = {
        .type = SL_LINEAR, // Type of easing
        .values = { // Values to interpolate 
            .from = 0,
            .to = 10
        },
        .time = 0 // Where in the interpolation curve to start. Generally you should keep this at 0 and should a value between [0, 1].
    };

    float l = slerp_to(my_lerp, 0.8); // 8.0
```

> [!NOTE]
> If the interpolation enum is an invalid value, the easing will default to `SL_LINEAR`

<br/>
The full list of easings and names can be seen in the slerp.h header.
# Pixel Glitch
A pixel sorting library.  

**Note** this library is still under development and not all planned features are available.

## Examples

| Original                  |  Sorted                               | Sorted                   |
|:-------------------------:|:--------------------------------------|:-------------------------|
|                           | `pixel-glitch images/profile.png`     | `pixel-glitch images/profile.png --reverse`  |
|![](./images/profile.png)  |  ![](./images/profile_sorted.png)     | ![](./images/profile_sorted_reversed.png)    |
|                           | `pixel-glitch images/monterey.png`    | `pixel-glitch images/monterey.png --reverse` |
|![](./images/monterey.png) |  ![](./images/monterey_sorted.png)    | ![](./images/monterey_sorted_reversed.png)   |
|                           | `pixel-glitch images/sunset.png`      | `pixel-glitch images/sunset.png --reverse`   |
|![](./images/sunset.png)   |  ![](./images/sunset_sorted.png)      | ![](./images/sunset_sorted_reversed.png)     |

## Compiling
```bash
make compile
```
## Running
```bash
pixel-glitch images/profile.png
```

## CLI Options
Available features are emboldened in the table below.

| CLI Arg     | Examples | Description     |
| :---        |    :----   |          ---: |
| <img width=250/> | <img width=800/> | <img width=500/> |
| --algorithm | Sorting algorithm to use.   | [`bubblesort`, `heapsort`, `insertionsort`, **`introsort`**, `mergesort`, `quicksort`]       | 
| --angle     | The angle to sort at.  Only used for `--shape line`     |[`0`, `90`, `235`]        | 
| --percent   | The sort percent to stop at.      |[**`100`**, `50`]        | 
| --reverse   | Reverses the sort direction. |        | 
| --segment   | Will segment the image and sort each segment separately. |        | 
| --shape     | The shape to follow when sorting.  `equation` allows for generic functions to be used in the form of `y = f(x)`  | [**`line`**, `circle`, `equation`] | 
| --value     | The value to use for sorting.  If `auto` will attempt to choose the most "distinct" value. | [`r`, `rg`, `rgba`, `auto`] | 
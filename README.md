3DS_Homebrew
============

Sample app with basic libraries for 3DS

http://gbatemp.net/threads/homebrew-development.360646/#post-4887740

Note:
psdraw still doesn't work! I wrote it on a paper sketch of stereographic coordinates translation, so probably the graphic result will not be very good. Please don't blame, it's only my first experiment.

This work is partially based on the work of other people (take a look at the linked gbatemp.net discussion), but i changed some function name to my own naming convection. 

I fixed a bug in the original pixel drawing function (it was out of sync by one pixel) and set the correct indexex for framebuffer=0 (still using postfix FRAME1 in the code, but I'll change it soon). The indexes for the other framebuffer should be right, but are not widely tested yet

Currently working on:
- swapping frame buffers
- getting input from 3DS buttons and circlepad
- fixing the 3DS effect


nop90

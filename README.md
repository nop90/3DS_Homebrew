3DS_Homebrew
============

Sample app with basic libraries for 3DS on barebone ARM 

NOTE: This lib is outdated

http://gbatemp.net/threads/homebrew-development.360646/#post-4887740

Note:
psdraw still doesn't work! I wrote it on a paper sketch of stereographic coordinates translation, so probably the graphic result will not be very good. Please don't blame, it's only my first experiment.

This work is partially based on the work of other people (take a look at the linked gbatemp.net discussion), but i changed some function name to my own naming convection. 

Currently working on:
- swapping frame buffers
- getting input from circlepad
- fixing the 3D effect


nop90

Changelog
============

01/18/2014 - Fixed buffer pointers and implemented HID management (only buttons. circlepad not yet).

01/17/2014 - First release. Fixed bug in original pixel drawing function from InsaneKane.

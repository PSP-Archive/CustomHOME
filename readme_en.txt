readme
-------------------------------------------------------------------------------------
[Introduction]
"CustomHOME" is the plugin that makes HOME MENU more convenient.

-------------------------------------------------------------------------------------
[Viable environment]
6.XX ME,PRO

-------------------------------------------------------------------------------------
[Installation]
1. Put "cushome" directory in seplugins directory on your PSP memory stick 
2. Download prxcmlib_pack.zip and Put "lib" directory in "seplugins" directory.
http://code.google.com/p/prx-common-libraries/downloads/list
3. and append ms0:/seplugins/cushome/cushome.prx to game.txt files.
4. Reboot your PSP.

*If you use other language  file, you need rename "lang.ini"
  Thanks Fsi09, red9350
-------------------------------------------------------------------------------------
[How to use]
The menu is displayed by pushing the Home button while playing a game.

*plugin Disable if you pressing HOME button and run the game.
*Setting menu show to press SELECT-button 2 seconds.
*when StopGame is desable, you can pause to press START-button.


*Exit Game		:Exit the game and return XMB.
*Reset Game		:Restart the game.(this function disabled when you use "Prometheus Iso Loader")
*Shutdown		:Shutdown PSP.
*Standby		:Suspend PSP.
*Pause/Resume	:Game pause / resume. (Only Stop Game is OFF )
*Back			:Close menu.
*ConnectUSB		:Connect USB
*PspStates		:Show PspStates menu


 Setting Menu
・SwapButton		：Change enter button(X or O)
・Mute			:Mute when menu show (ON or OFF)
・StopGame		:Stop the game when the menu display (ON or OFF)
・MenuPos		:Change menu position(UP or DOWN)
・ColorSetting	:Change color
					press [<-] or [->] to choose ,and press enter button.
					if DoubleColor is enable, menu display striped.
・MenuSetting	:Menu sort
					change disp / hide to press enter button.
					You can sort to press [] and up-buttn, down-button.
・BarSetting		:Setting bar item positon.
					Change left-justified, right-justified, hide to press enter button.
					Change disp position to press /\ and <-,->,up-button,down-button.
					Change disp priorities to press [] and up-button,down-button.
					bar pattern change to press [<-], [->].

-------------------------------------------------------------------------------------
[PSPStates.prx]
please use "pspstates_kai.prx".
*Can't use "pspstates.prx"

*How to use pspstates in CustomHOME
Put "pspstates_kai.prx" in seplugins directory
"PSPStates" enable on CustomHOME setteings.

How to use is displayed on PSPStates menu. Please check there.

-------------------------------------------------------------------------------------
[How to edit date format]
you can use these things.

%weekday
%day
%monthname
%monthnum
%year
%hour24
%hour12 (time format 12)
%min
%sec
%ampm

Example : [%weekday %monthnum-%day-%year %hour24]
Example2: %weekday, %day. %monthname %year %hour12:%min:%sec %ampm

-------------------------------------------------------------------------------------
[update]
1.3.4(update 2013/06/21)
[!]Fixed a bug that some wallpaper is not displayed well.
[!]Update cushome.prs.

1.3.3(update 2013/04/07)
[!]Fixed a bug that wallpaper appears only once.

1.3.2(update 2013/04/06)
[!]Fixed a bug that you can not exit in some games.
[!]Changed how to operate the menu of PSPStates.
(In addition, please update prxcmlib_pack.)

1.3.1(update 2013/03/17)
[!]Fixed some bugs.

1.3.0(update 2013/03/14)
[+]Corresponds to the loading of the wallpaper.
(please place the 480*272 size BMP to cushome/image/ folder.If you place it with multiple, it is chosen at random.)

1.2.1(update 2013/03/10)
[!]Fixed a bug this plug-in does not work on some homebrew.

1.2.0(update 2013/03/09)
[!]Changed the specification significantly.
[!]Increase degree of stability.
[!]Changed to run on homebrew valid HOME screen.
[+]Added the ability to save state by pressing yes while holding down the L trigger in Exit Game dialog.(Go only)
(Please release the L trigger when HOME screen is closed. In addition, this feature is temporary and I plan to add to the menu after.)

1.1.0(update 2012/02/14)
[!]Fixed a bug that does not work on PSP1000
[+]Add Chinese ini file
[!]Fixed many minor bugs

1.0.0(update 2012/01/01)
[!]End beta version, became the official version!
[+]Settings can be specified in detail.
[!]Separate configuration files and language files(So, please update ini file.)
[-]Stop support Homebrew.

beta 0.9.1(update 2011/10/09)
[!]Change CPU/BUS display position.

beta 0.9.0(update 2011/10/09)
[+]add edit plugin-txt function.
This can not load up to only 22 lines.

beta 0.8.3(update 2011/10/02)
[!]fix suspend thread bug.

beta 0.8.2(update 2011/09/25)
[+]add disp CPU/BUS function.
[!]fix pspstates_kai.prx bug.
[!]update iniLibraryPortable.

beta 0.8.1(update 2011/09/19)
[!]fix GameReset bug.

beta 0.8.0(update 2011/09/18)
[!]fix a few bugs.
[!]change draw way
[!]update cushome.prs
[+]add connect USB function
[+]add color change type 

beta 0.7.2(update 2011/09/01)
[!]fix a few bugs.
[+]add Homebrew option.
[+]add selectable colors.
 (chose pressing [<-] or [->], and decide pressing [X])
[+]add ini file.（Thanks Llywelyn）

beta 0.7.1(update 2011/08/16)
[!]fix ini file bug.
  (please replace new ini file)

beta 0.7.0(update 2011/08/16)
[+]Supported CFW6.60
[!]fix "%monthname" display
[+]Were able to stop the game by pressing START.
[+]Was to open the setting screen by pressing SELECT.
[!]fix a few bugs.
[+]Changes to [X] button to select [O] button to return and close the menu by pressing the HOME.
 (Alternates with [○] and [×] have enabled SwapButton.)
[+]Supported spstates_kai.prx(pspstates is not Supported.)
[+]add "states_menu_pict" function.(Thanks plum, hiroi01, neur0n)
[!]IniLibraryPortable changed from iniLibrary. (Thanks hiroi01)
[-]Remove some functions.
[!]update cushome.prs
[+]add icon(Thanks SAL)

beta 0.6.4(update 2011/07/24)
[fix]fix game reset function.
[change]Changed to work only with the game that is shown the original HOME menu.
*There is no need to update cmlib

beta 0.6.3(update 2011/07/16)
[fix]Support for FW6.39 - 05g model
[change]Changing the settings menu to new style.
[change]Change the position of the game ID, Brightness, name of the game
[add]Add brightness icon.(Thanks Lock!）

beta 0.6.2(update 2011/07/10)
[fix]ifx battery icon.
[add]add brightness display.
[change]Changes to the selected point at the top when you redisplay the menu.
[add]Supported pspstates

beta 0.6.1(update 2011/6/25)
[add]You can display warning when battery is low and menu display.
[add]prxlibmenu.prx and cmLibMask.prx support.
 So,please place the lib folder.（They are also used pwrCtrl.）
[add]You can network update from Internet radio.
 please place the "cushome.prs" onms0:/PSP/RADIOPLAYER.

beta 0.6
[add]Menu and Volume is able to hide after a few seconds. (Thanks SnyFbSx)
[add]The settings can detail change.
[add]Change font color (red, green or blue)
[add]hide the menu when pressing "<-" ,display the menu when pressing"->".

beta 0.5fix
[fix]Fix language display.
[fix]Fix readme txt.

beta 0.5
[fix]Fixed not disabled bug when you start pressing HOME buttons.
[fix]Fixed Do not displayed the battery time remaining on PSPGo.
[fix]Fixed button behavior bug that happens when the Menu.
[change]Remove the display brightness.
[update]The description can enabled / disable
[add]German support. (Fsi09 Thank you!)
[add]Support CFW6.39.
[add]Add a confirmation dialog.
[add]The trial games's Game ID is displayed..
[add]Add a function that stop the game when the menu display.
[add]Add pause function (Only Stop Game is OFF)

beta 0.4
[add]GameID is displayed.(You can change from setteings.)
[update]Support PSPGo and Homebrew.
[add]Add mute function.(You can change from setteings.)
[fix]Fixed settings are not saved.

beta 0.3
[fix]You don't need restart after changing.
[add]Add restart game function.（this function disabled when you use "Prometheus Iso Loader".）
[update]Fixed to show all games（There are some flickers of the screen and noises of the sound.）
[add]The game name is displayed.
[add]Customizable dates format is now available!
[change]PSPGo and PS1 are not support.

beta 0.2
[add]The volume and brightness are displayed.
[add]The language change support.(Japanese or English.)
[add]The button change support.（you need restart after changing.）

-------------------------------------------------------------------------------------
[Thanks]
I was supported by the following people.(The titles omitted)
hiroi01, SnyFbSx, j416dy, neur0n, plum, mafu, Dadrfy, estuibal.

iniLibrary		by hiroi01
LibMenu			by maxem
prxlibmenu		by wn

translate		SnyFbSx, mamosuke, Misaka
german translate	Fsi09, flofrucht

Thanks every developers.

-------------------------------------------------------------------------------------
[Contact]
twitter   http://twitter.com/ABCanG1015
web       http://abcang.net/
mail      abcang1015@gmail.com

FernetWoods_MapScripts::
	.byte 0


FernetWoods_EventScript_Ed::
	trainerbattle_single TRAINER_ED, FernetWoods_EventScript_Ed_Text_0, FernetWoods_EventScript_Ed_Text_1
	msgbox FernetWoods_EventScript_Ed_Text_2, MSGBOX_AUTOCLOSE
	end


FernetWoods_EventScript_Jonas::
	trainerbattle_single TRAINER_JONAS, FernetWoods_EventScript_Jonas_Text_0, FernetWoods_EventScript_Jonas_Text_1
	msgbox FernetWoods_EventScript_Jonas_Text_2, MSGBOX_AUTOCLOSE
	end


FernetWoods_EventScript_Ed_Text_0:
	.string "I got lost in these woods. \n Fortunately I caught a new POKéMON!$"

FernetWoods_EventScript_Ed_Text_1:
	.string "Seems my new POKéMON couldn't win...$"

FernetWoods_EventScript_Ed_Text_2:
	.string "I think I'm growing a liking to these\n"
	.string "woods.$"

FernetWoods_EventScript_Jonas_Text_0:
	.string "I lay in ambush, and a TRAINER has\nlanded in my trap!$"

FernetWoods_EventScript_Jonas_Text_1:
	.string "If you don't lose, how am I supposed\nto have fun playing ninja?$"

FernetWoods_EventScript_Jonas_Text_2:
	.string "I'm going to ambush a weaker-looking\n"
	.string "TRAINER next time.$"

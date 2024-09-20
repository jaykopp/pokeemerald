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


FernetWoods_EventScript_RivalTrigger1::
	applymovement 1, FernetWoods_Rival_Movement1
	goto FernetWoods_EventScript_Rival
	end


FernetWoods_EventScript_RivalTrigger2::
	applymovement 1, FernetWoods_Rival_Movement2
	goto FernetWoods_EventScript_Rival
	end


FernetWoods_EventScript_Rival::
	compare VAR_FERNET_WOODS_RIVAL_STATE, 0
	goto_if_eq FernetWoods_EventScript_Rival_2
FernetWoods_EventScript_Rival_1:
	end

FernetWoods_EventScript_Rival_2:
	lockall
	msgbox FernetWoods_EventScript_Rival_Text_0
	switch VAR_STARTER_MON
	case 0, FernetWoods_EventScript_Rival_6
	case 1, FernetWoods_EventScript_Rival_7
	case 2, FernetWoods_EventScript_Rival_8
FernetWoods_EventScript_Rival_4:
	msgbox FernetWoods_EventScript_Rival_Text_2, MSGBOX_DEFAULT
	setvar VAR_FERNET_WOODS_RIVAL_STATE, 1
	release
	goto FernetWoods_EventScript_Rival_1

FernetWoods_EventScript_Rival_6:
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, FernetWoods_EventScript_Rival_Text_1
	goto FernetWoods_EventScript_Rival_4

FernetWoods_EventScript_Rival_7:
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, FernetWoods_EventScript_Rival_Text_1
	goto FernetWoods_EventScript_Rival_4

FernetWoods_EventScript_Rival_8:
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, FernetWoods_EventScript_Rival_Text_1
	goto FernetWoods_EventScript_Rival_4


FernetWoods_Rival_Movement1:
	walk_right
	walk_right
	step_end

FernetWoods_Rival_Movement2:
	walk_right
	walk_down
	walk_right
	step_end

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

FernetWoods_EventScript_Rival_Text_0:
	.string "Hey {PLAYER}! I heard grandpa gave\n"
	.string "you a Pokémon. He gave me one too!\l"
	.string "Let's battle with them!$"

FernetWoods_EventScript_Rival_Text_1:
	.string "I lost?$"

FernetWoods_EventScript_Rival_Text_2:
	.string "Damn! You already have gotten the hang\n"
	.string "of battling, huh?$"

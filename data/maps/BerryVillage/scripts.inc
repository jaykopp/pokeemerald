BerryVillage_MapScripts::
	.byte 0


BerryVillage_EventScript_Guy::
	lockall
	face_player
	msgbox BerryVillage_EventScript_Guy_Text_0, MSGBOX_AUTOCLOSE
	releaseall
	end


BerryVillage_EventScript_Lady::
	lockall
	face_player
	msgbox BerryVillage_EventScript_Lady_Text_0, MSGBOX_AUTOCLOSE
	releaseall
	end


BerryVillage_EventScript_LittleBoy::
	lockall
	msgbox BerryVillage_EventScript_LittleBoy_Text_0
	applymovement 15, BerryVillage_Movement_Littleboy
	waitmovement 0
	applymovement 16, BerryVillage_Movement_Dad1
	msgbox BerryVillage_EventScript_LittleBoy_Text_1
	applymovement 16, BerryVillage_Movement_Dad2
	waitmovement 0
	releaseall
	end


BerryVillage_Movement_Littleboy:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

BerryVillage_Movement_Dad1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

BerryVillage_Movement_Dad2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BerryVillage_EventScript_Guy_Text_0:
	.string "I heard that this village had some\n"
	.string "interesting berries.\n"
	.string "I never knew how interesting they were!$"

BerryVillage_EventScript_Lady_Text_0:
	.string "I used to be a Pokemon trainer, aiming\n"
	.string "to be the very best.\n"
	.string "After this village sprung up I decided\l"
	.string "to settle down.$"

BerryVillage_EventScript_LittleBoy_Text_0:
	.string "You just don't know how awesome I am at\n"
	.string "Pokémon battling!$"

BerryVillage_EventScript_LittleBoy_Text_1:
	.string "If only I could get the kid to\n"
	.string "understand how wast the world of\l"
	.string "Pokémon battling really is...$"

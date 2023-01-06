.set LOCALID_STEVEN, 19

Route118_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
	.byte 0

Route118_OnTransition:
	call GabbyAndTy_EventScript_UpdateLocation
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_StartGroudonWeather
	end

Route118_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_EventScript_PlaceTilesRoute118East
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_EventScript_PlaceTilesRoute118West
	end

Route118_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route118_EventScript_GoodRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route118_EventScript_ReceiveGoodRod
	goto_if_eq VAR_RESULT, NO, Route118_EventScript_DeclineGoodRod
	end

Route118_EventScript_ReceiveGoodRod::
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_DeclineGoodRod::
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_ReceivedGoodRod::
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Girl::
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

Route118_EventScript_RouteSignMauville::
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route118_EventScript_RouteSign119::
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
	end

Route118_EventScript_StevenTrigger0::
	lockall
	setvar VAR_0x8008, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge0
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger1::
	lockall
	setvar VAR_0x8008, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger2::
	lockall
	setvar VAR_0x8008, 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge2
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger::
	playse SE_LEDGE
	applymovement LOCALID_STEVEN, Route118_Movement_StevenJumpLedge
	waitmovement 0
	delay 30
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, Route118_EventScript_StevenExit0
	call_if_eq VAR_0x8008, 1, Route118_EventScript_StevenExit1
	call_if_eq VAR_0x8008, 2, Route118_EventScript_StevenExit2
	setvar VAR_ROUTE118_STATE, 1
	removeobject LOCALID_STEVEN
	releaseall
	end

Route118_EventScript_StevenExit0::
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit0
	waitmovement 0
	return

Route118_EventScript_StevenExit1::
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
	waitmovement 0
	return

Route118_EventScript_StevenExit2::
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit2
	waitmovement 0
	return

Route118_Movement_PlayerWatchStevenExit:
	delay_16
	walk_in_place_faster_right
	step_end

Route118_Movement_StevenApproachLedge0:
	walk_left
	step_end

Route118_Movement_StevenApproachLedge2:
	walk_right
	step_end

Route118_Movement_StevenJumpLedge:
	jump_2_down
	delay_16
	walk_down
	step_end

Route118_Movement_StevenExit0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_StevenExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_StevenExit2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_EventScript_Rose::
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Route118_EventScript_RegisterRose
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchRose
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterRose::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROSE_1
	release
	end

Route118_EventScript_RematchRose::
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_RoseRematchIntro, Route118_Text_RoseRematchDefeat
	msgbox Route118_Text_RosePostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Barny::
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Wade::
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Dalton::
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Route118_EventScript_RegisterDalton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchDalton
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterDalton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DALTON_1
	release
	end

Route118_EventScript_RematchDalton::
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Chester::
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Deandre::
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_Text_StevenQuestions:
	.string "STEVEN: Hi, {PLAYER}{KUN}!\p"
	.string "It's me, STEVEN!\n"
	.string "We met in the cave near DEWFORD.\p"
	.string "Have you met many kinds of POKéMON\n"
	.string "since I last saw you?\p"
	.string "There are many, many kinds of POKéMON\n"
	.string "in this wide world of ours.\p"
	.string "If you wanted to raise only your\n"
	.string "favorites, that's fine.\p"
	.string "Perhaps you find it more fun to raise\n"
	.string "all sorts of POKéMON.\p"
	.string "As a TRAINER of POKéMON,\n"
	.string "what do you think?\p"
	.string "Of course, it's not any of my business.\p"
	.string "It would be nice if we were to meet\n"
	.string "again somewhere.$"

Route118_Text_YouAgreeGoodRodIsGood:
	.string "Hmm!\n"
	.string "A GOOD ROD is really good!\p"
	.string "Wouldn't you agree?$"

Route118_Text_IdenticalMindsTakeThis:
	.string "Hmm!\n"
	.string "We're of identical minds!\p"
	.string "Hmm!\n"
	.string "Take this GOOD ROD!$"

Route118_Text_TryYourLuckFishing:
	.string "Wherever there's water, try your luck\n"
	.string "at fishing.$"

Route118_Text_DontYouLikeToFish:
	.string "Don't you like to fish?$"

Route118_Text_TryCatchingMonWithGoodRod:
	.string "Try catching all sorts of POKéMON\n"
	.string "with your GOOD ROD.$"

Route118_Text_CanCrossRiversWithSurf:
	.string "Even if there isn't a boat, you can\n"
	.string "cross rivers and the sea if you have\l"
	.string "a POKéMON that knows SURF.\p"
	.string "POKéMON can be counted on to do so\n"
	.string "much!$"

Route118_Text_RouteSignMauville:
	.string "ROUTE 118\n"
	.string "{LEFT_ARROW} MAUVILLE CITY$"

Route118_Text_RouteSign119:
	.string "ROUTE 118\n"
	.string "{UP_ARROW} ROUTE 119$"

Route118_EventScript_LittleBoyTrigger0::
	setvar VAR_TEMP_1, 0
	goto Route118_EventScript_LittleBoyScript
	return


Route118_EventScript_LittleBoyTrigger1::
	setvar VAR_TEMP_1, 1
	goto Route118_EventScript_LittleBoyScript
	return


Route118_EventScript_LittleBoyTrigger2::
	setvar VAR_TEMP_1, 2
	goto Route118_EventScript_LittleBoyScript
	return


Route118_EventScript_LittleBoyScript::
	lockall
	applymovement 21, Route118_LittleBoyMovement6
	msgbox Route118_EventScript_LittleBoyScript_Text_0
	msgbox Route118_EventScript_LittleBoyScript_Text_1
	applymovement 21, Route118_LittleBoyMovement1
	compare VAR_TEMP_1 == 0, 0
	goto_if_ne Route118_EventScript_LittleBoyScript_2
	compare VAR_TEMP_1 == 1, 0
	goto_if_ne Route118_EventScript_LittleBoyScript_3
	applymovement 21, Route118_LittleBoyMovement4
Route118_EventScript_LittleBoyScript_1:
	msgbox Route118_EventScript_LittleBoyScript_Text_2
	trainerbattle_no_intro TRAINER_JIMMY, Route118_EventScript_LittleBoyScript_Text_3
	msgbox Route118_EventScript_LittleBoyScript_Text_4
	setvar VAR_ROUTE118_STATE, 1
	compare VAR_TEMP_1 == 0, 0
	goto_if_ne Route118_EventScript_LittleBoyScript_8
	compare VAR_TEMP_1 == 1, 0
	goto_if_ne Route118_EventScript_LittleBoyScript_8
	compare VAR_TEMP_1 == 2, 0
	goto_if_ne Route118_EventScript_LittleBoyScript_9
Route118_EventScript_LittleBoyScript_7:
	applymovement 21, Route118_LittleBoyMovement5
	removeobject 21
	applymovement 22, Route118_LittleBoyMovement9
	compare VAR_TEMP_1 == 0, 0
	goto_if_ne Route118_EventScript_LittleBoyScript_15
	compare VAR_TEMP_1 == 2, 0
	goto_if_ne Route118_EventScript_LittleBoyScript_16
Route118_EventScript_LittleBoyScript_14:
	msgbox Route118_EventScript_LittleBoyScript_Text_5
	giveitem ITEM_SALAC_BERRY
	giveitem ITEM_LIECHI_BERRY
	giveitem ITEM_PETAYA_BERRY
	msgbox Route118_EventScript_LittleBoyScript_Text_6
	setflag FLAG_ROUTE118_LITTLE_BOY
	releaseall
	end

Route118_EventScript_LittleBoyScript_2:
	applymovement 21, Route118_LittleBoyMovement2
	goto Route118_EventScript_LittleBoyScript_1

Route118_EventScript_LittleBoyScript_3:
	applymovement 21, Route118_LittleBoyMovement3
	goto Route118_EventScript_LittleBoyScript_1

Route118_EventScript_LittleBoyScript_8:
	applymovement 21, Route118_LittleBoyMovement7
	goto Route118_EventScript_LittleBoyScript_7

Route118_EventScript_LittleBoyScript_9:
	applymovement 21, Route118_LittleBoyMovement8
	goto Route118_EventScript_LittleBoyScript_7

Route118_EventScript_LittleBoyScript_15:
	applymovement 22, Route118_FatherMovement1
	goto Route118_EventScript_LittleBoyScript_14

Route118_EventScript_LittleBoyScript_16:
	applymovement 22, Route118_FatherMovement2
	goto Route118_EventScript_LittleBoyScript_14


Route118_EventScript_Father::
	lockall
	faceplayer
	msgbox Route118_EventScript_LittleBoyScript_Text_6
	releaseall
	end


Route118_LittleBoyMovement1:
	emote_exclamation_mark
	face_down
	step_end

Route118_LittleBoyMovement2:
	walk_fast_down
	step_end

Route118_LittleBoyMovement3:
	walk_fast_down
	walk_fast_right
	face_down
	step_end

Route118_LittleBoyMovement4:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	face_down
	step_end

Route118_LittleBoyMovement5:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route118_LittleBoyMovement6:
	jump_in_place_up_down
	step_end

Route118_LittleBoyMovement7:
	walk_fast_right
	step_end

Route118_LittleBoyMovement8:
	walk_fast_left
	step_end

Route118_LittleBoyMovement9:
	walk_down
	step_end

Route118_FatherMovement1:
	walk_left
	face_down
	step_end

Route118_FatherMovement2:
	walk_right
	face_down
	step_end

Route118_Worker1::
	lock
	faceplayer
	msgbox Route118_Worker1_Text_0
	release
	end


Route118_Worker2::
	lock
	faceplayer
	msgbox Route118_Worker2_Text_0
	release
	end


Route118_Worker3::
	lock
	faceplayer
	msgbox Route118_Worker3_Text_0
	release
	end


Route118_EventScript_LittleBoyScript_Text_0:
	.string "BOY: I want to be the very best! Like no\n"
	.string "one ever was!$"

Route118_EventScript_LittleBoyScript_Text_1:
	.string "MAN: There are plenty of strong\n"
	.string "trainers out there!$"

Route118_EventScript_LittleBoyScript_Text_2:
	.string "BOY: You look strong! Battle me!$"

Route118_EventScript_LittleBoyScript_Text_3:
	.string "There are trainers stronger than me?$"

Route118_EventScript_LittleBoyScript_Text_4:
	.string "BOY: I can't believe my ultimate berry\n"
	.string "style did not work! Maybe I need to\l"
	.string "prepare a bit more...$"

Route118_EventScript_LittleBoyScript_Text_5:
	.string "Thank you for battling my son. He\n"
	.string "doesn't know much besides the life in\l"
	.string "the village, so battling in the wider\l"
	.string "world would come as a shock t him. I am\l"
	.string "glad his first battle outside the\l"
	.string "village was someone as capable as you.\p"
	.string "Take this as a token of my gratitude.$"

Route118_EventScript_LittleBoyScript_Text_6:
	.string "My father is the Berry Master. He grows\n"
	.string "all kinds of berries. I hope you find\l"
	.string "some use for them.$"

Route118_Worker1_Text_0:
	.string "I can't believe we are almost finished\n"
	.string "building the road between MAUVILLE\l"
	.string "and LILYCOVE.$"

Route118_Worker2_Text_0:
	.string "The bridge to MAUVILLE CITY is nearly\n"
	.string "complete. After this I am taking a well\l"
	.string "earned vacation.$"

Route118_Worker3_Text_0:
	.string "I used to be Pokémon trainer like you,\n"
	.string "but I never got the hang of battling.\l"
	.string "Building bridges is where my talent\l"
	.string "lies!$"

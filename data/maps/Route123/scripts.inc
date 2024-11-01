Route123_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
	.byte 0

Route123_OnTransition:
	special SetRoute123Weather
	end

Route123_EventScript_GigaDrainGirl::
	lock
	faceplayer
	goto_if_set FLAG_BLACK_GLASSES_GIRL, Route123_EventScript_ReceivedGigaDrain
	msgbox Route123_Text_LoveGrassMonsHaveAny, MSGBOX_DEFAULT
	special IsGrassTypeInParty
	goto_if_eq VAR_RESULT, FALSE, Route123_EventScript_NoGrassMons
	msgbox Route123_Text_YouLikeGrassMonsTooHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_BLACK_GLASSES_GIRL
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_NoGrassMons::
	release
	end

Route123_EventScript_ReceivedGigaDrain::
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RouteSign::
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
	end

Route123_EventScript_RouteSignMtPyre::
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
	end

Route123_EventScript_BerryMastersHouseSign::
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
	end

// Route123_EventScript_Cameron::
// 	trainerbattle_single TRAINER_CAMERON_1, Route123_Text_CameronIntro, Route123_Text_CameronDefeat, Route123_EventScript_RegisterCameron
// 	specialvar VAR_RESULT, ShouldTryRematchBattle
// 	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchCameron
// 	msgbox Route123_Text_CameronPostBattle, MSGBOX_DEFAULT
// 	release
// 	end

// Route123_EventScript_RegisterCameron::
// 	special PlayerFaceTrainerAfterBattle
// 	waitmovement 0
// 	msgbox Route123_Text_CameronRegister, MSGBOX_DEFAULT
// 	register_matchcall TRAINER_CAMERON_1
// 	release
// 	end

// Route123_EventScript_RematchCameron::
// 	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_CameronRematchIntro, Route123_Text_CameronRematchDefeat
// 	msgbox Route123_Text_CameronPostRematch, MSGBOX_AUTOCLOSE
// 	end

// Route123_EventScript_jax::
//	trainerbattle_single TRAINER_jax_1, Route123_Text_jaxIntro, Route123_Text_jaxDefeat, Route123_EventScript_Registerjax
//	specialvar VAR_RESULT, ShouldTryRematchBattle
//	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_Rematchjax
//	release
//	end

Route123_EventScript_Registerjax::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_jaxRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAX_1
	release
	end

Route123_EventScript_Rematchjax::
	trainerbattle_rematch TRAINER_JAX_1, Route123_Text_jaxRematchIntro, Route123_Text_jaxRematchDefeat
	msgbox Route123_Text_jaxPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Miu::
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_MiuIntro, Route123_Text_MiuDefeat, Route123_Text_MiuNotEnoughMons
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Yuki::
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_YukiIntro, Route123_Text_YukiDefeat, Route123_Text_YukiNotEnoughMons
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Kindra::
	trainerbattle_single TRAINER_KINDRA, Route123_Text_KindraIntro, Route123_Text_KindraDefeat
	msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Alberto::
	trainerbattle_single TRAINER_ALBERTO, Route123_Text_AlbertoIntro, Route123_Text_AlbertoDefeat
	msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Ed::
	trainerbattle_single TRAINER_ED, Route123_Text_EdIntro, Route123_Text_EdDefeat
	msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jonas::
	trainerbattle_single TRAINER_JONAS, Route123_Text_JonasIntro, Route123_Text_JonasDefeat
	msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jazmyn::
	trainerbattle_single TRAINER_JAZMYN, Route123_Text_JazmynIntro, Route123_Text_JazmynDefeat
	msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Fernando::
	trainerbattle_single TRAINER_FERNANDO_1, Route123_Text_FernandoIntro, Route123_Text_FernandoDefeat, Route123_EventScript_RegisterFernando
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchFernando
	msgbox Route123_Text_FernandoPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterFernando::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_FernandoRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_FERNANDO_1
	release
	end

Route123_EventScript_RematchFernando::
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_FernandoRematchIntro, Route123_Text_FernandoRematchDefeat
	msgbox Route123_Text_FernandoPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_Text_LoveGrassMonsHaveAny:
	.string "I love GRASS-type POKéMON!\p"
	.string "Do you have any GRASS-type POKéMON?$"

Route123_Text_YouLikeGrassMonsTooHaveThis:
	.string "Oh?\p"
	.string "You like GRASS-type POKéMON, too,\n"
	.string "don't you?\p"
	.string "I'm so happy, you can have this!\n"
	.string "It's a token of our friendship.$"

Route123_Text_CheckTreesWithMyGrassMon:
	.string "I check trees with my GRASS-type\n"
	.string "POKéMON. I'm like a tree doctor.$"

Route123_Text_RouteSign:
	.string "{RIGHT_ARROW} ROUTE 123\n"
	.string "{LEFT_ARROW} ROUTE 118$"

Route123_Text_RouteSignMtPyre:
	.string "{UP_ARROW} MT. PYRE\n"
	.string "“Forbidden to the faint of heart.”$"

Route123_Text_BerryMastersHouse:
	.string "BERRY MASTER'S HOUSE$"

Route123_EventScript_BirchsTrigger1::
	setvar VAR_TEMP_1, 0
	goto Route123_EventScript_BirchsRescue
	end


Route123_EventScript_BirchsTrigger2::
	setvar VAR_TEMP_1, 1
	goto Route123_EventScript_BirchsRescue
	end


Route123_EventScript_BirchsTrigger3::
	setvar VAR_TEMP_1, 2
	goto Route123_EventScript_BirchsRescue
	end


Route123_EventScript_BirchsRescue::
	lockall
	playbgm MUS_HELP, TRUE
	msgbox Route123_EventScript_BirchsRescue_Text_0, MSGBOX_AUTOCLOSE
	switch VAR_TEMP_1
	case 0, Route123_EventScript_BirchsRescue_3
	case 2, Route123_EventScript_BirchsRescue_4
Route123_EventScript_BirchsRescue_1:
	applymovement 22, BirchChase
	applymovement 23, BirchChase
	waitmovement 0
	msgbox Route123_EventScript_BirchsRescue_Text_1, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	removeobject 23
	setwildbattle SPECIES_ZIGZAGOON, 7, ITEM_ORAN_BERRY
	dowildbattle
	setflag FLAG_ROUTE_123_BIRCH_RESCUE
	setflag FLAG_ROUTE_123_ZIGZAGOON
	msgbox Route123_EventScript_BirchsRescue_Text_2, MSGBOX_AUTOCLOSE
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route123_EventScript_BirchsRescue_Text_3
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	msgbox Route123_EventScript_BirchsRescue_Text_4, MSGBOX_DEFAULT
	releaseall
	end

Route123_EventScript_BirchsRescue_3:
	applymovement 22, BirchTrigger1
	applymovement 23, BirchTrigger1
	goto Route123_EventScript_BirchsRescue_1

Route123_EventScript_BirchsRescue_4:
	applymovement 22, BirchTrigger3
	applymovement 23, BirchTrigger3
	goto Route123_EventScript_BirchsRescue_1


Route123_EventScript_GlassesGirl::
	lock
	faceplayer
	goto_if_unset FLAG_BLACK_GLASSES_GIRL, Route123_EventScript_GlassesGirl_2
	msgbox Route123_EventScript_GlassesGirl_Text_5, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route123_EventScript_GlassesGirl_7
	msgbox Route123_EventScript_GlassesGirl_Text_7
Route123_EventScript_GlassesGirl_1:
	release
	end

Route123_EventScript_GlassesGirl_2:
	msgbox Route123_EventScript_GlassesGirl_Text_0
	checkitem ITEM_BLACK_GLASSES
	compare VAR_RESULT, 1
	goto_if_eq Route123_EventScript_GlassesGirl_5
	goto Route123_EventScript_GlassesGirl_1

Route123_EventScript_GlassesGirl_5:
	msgbox Route123_EventScript_GlassesGirl_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route123_EventScript_GlassesGirl_10
	msgbox Route123_EventScript_GlassesGirl_Text_4
	goto Route123_EventScript_GlassesGirl_1

Route123_EventScript_GlassesGirl_7:
	msgbox Route123_EventScript_GlassesGirl_Text_6
	special HealPlayerParty
	waitmessage
	goto Route123_EventScript_GlassesGirl_1

Route123_EventScript_GlassesGirl_10:
	msgbox Route123_EventScript_GlassesGirl_Text_2
	removeitem ITEM_BLACK_GLASSES
	special HealPlayerParty
	waitmessage
	setflag FLAG_BLACK_GLASSES_GIRL
	msgbox Route123_EventScript_GlassesGirl_Text_3
	goto Route123_EventScript_GlassesGirl_1


Route123_EventScript_Davis::
	trainerbattle_single TRAINER_DAVIS, Route123_Text_DavisIntro, Route123_Text_DavisDefeat
	msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
	end


Route123_EventScript_Wendell::
	trainerbattle_single TRAINER_WENDELL, Route123_EventScript_Wendell_Text_0, Route123_EventScript_Wendell_Text_1
	msgbox Route123_EventScript_Wendell_Text_2, MSGBOX_AUTOCLOSE
	end


Route123_EventScript_Jax::
	trainerbattle_single TRAINER_JAX_1, Route123_EventScript_Jax_Text_0, Route123_EventScript_Jax_Text_1
	msgbox Route123_EventScript_Jax_Text_2, MSGBOX_DEFAULT
	release
	end


Route123_EventScript_Frederick::
	trainerbattle_single TRAINER_FREDRICK, Route123_EventScript_Frederick_Text_0, Route123_EventScript_Frederick_Text_1
	msgbox Route123_EventScript_Frederick_Text_2, MSGBOX_AUTOCLOSE
	end


Route123_EventScript_Davido::
	trainerbattle_single TRAINER_DAVIDO, Route123_EventScript_Davido_Text_0, Route123_EventScript_Davido_Text_1
	msgbox Route123_EventScript_Davido_Text_2, MSGBOX_AUTOCLOSE
	end


Route123_EventScript_Caleb::
	trainerbattle_single TRAINER_CALEB, Route123_EventScript_Caleb_Text_0, Route123_EventScript_Caleb_Text_1
	msgbox Route123_EventScript_Caleb_Text_2, MSGBOX_AUTOCLOSE
	end


Route123_EventScript_Braxton::
	trainerbattle_single TRAINER_BRAXTON, Route123_EventScript_Braxton_Text_0, Route123_EventScript_Braxton_Text_1
	msgbox Route123_EventScript_Braxton_Text_2, MSGBOX_AUTOCLOSE
	end


BirchChase:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BirchTrigger1:
	walk_down
	step_end

BirchTrigger3:
	walk_up
	step_end

Route123_EventScript_BirchsRescue_Text_0:
	.string "H-help me!$"

Route123_EventScript_BirchsRescue_Text_1:
	.string "This Zigzagoon is chasing me! Please\n"
	.string "help me by battling it!$"

Route123_EventScript_BirchsRescue_Text_2:
	.string "Whew…\p"
	.string "You saved me!\n"
	.string "I can't thank you enough.\p"
	.string "Oh?\n"
	.string "You're travelling to experience the\l"
	.string "world?\p"
	.string "Well if you're going to explore the world\n"
	.string "of Pokémon this might come in handy!$"

Route123_EventScript_BirchsRescue_Text_3:
	.string "{PLAYER} received the POKéDEX!$"

Route123_EventScript_BirchsRescue_Text_4:
	.string "That right there is a POKéDEX. It\n"
	.string "contains information on POKéMON you\l"
	.string "have caught. Come visit me in\l"
	.string "Littleroot Town if you get the chance.$"

Route123_EventScript_GlassesGirl_Text_0:
	.string "I think I lost my shades somewhere in\n"
	.string "the tall grass. I'm a total coward\l"
	.string "though, so I'm scared of the wild\l"
	.string "POKéMON there. Can you help me find my\l"
	.string "them?$"

Route123_EventScript_GlassesGirl_Text_1:
	.string "Those BLACKGLASSES! Can I have them?\n"
	.string "I'll heal you up any time you like in\l"
	.string "exchange.$"

Route123_EventScript_GlassesGirl_Text_2:
	.string "Thank you so much! Here, let me heal\n"
	.string "your POKéMON.$"

Route123_EventScript_GlassesGirl_Text_3:
	.string "Don't I look stylish with my shades?$"

Route123_EventScript_GlassesGirl_Text_4:
	.string "Rude! I'm never speaking to you again.\n"
	.string "You know, unless you give me the\l"
	.string "BLACKGLASSES.$"

Route123_EventScript_GlassesGirl_Text_5:
	.string "Do you need another heal?$"

Route123_EventScript_GlassesGirl_Text_6:
	.string "You got it!$"

Route123_EventScript_GlassesGirl_Text_7:
	.string "If you change your mind, let me know.$"

Route123_EventScript_Wendell_Text_0:
	.string "I'm tired of working. Let's battle\n"
	.string "instead!$"

Route123_EventScript_Wendell_Text_1:
	.string "Damn, back to work I guess.$"

Route123_EventScript_Wendell_Text_2:
	.string "Battling can be so tiresome as well...$"

Route123_EventScript_Jax_Text_0:
	.string "Let's work ourselves to the bone.$"

Route123_EventScript_Jax_Text_1:
	.string "I'm exhausted. Fantastic!$"

Route123_EventScript_Jax_Text_2:
	.string "Nothing beats coming home tired after a\n"
	.string "hard days work.$"

Route123_EventScript_Frederick_Text_0:
	.string "I'm doing a school project on the new\n"
	.string "road they're building. Battle me in the\l"
	.string "study break!$"

Route123_EventScript_Frederick_Text_1:
	.string "Breaks over I guess...$"

Route123_EventScript_Frederick_Text_2:
	.string "The road has been built on time and on\n"
	.string "schedule. It's almost as good as my\l"
	.string "report!$"

Route123_EventScript_Davido_Text_0:
	.string "You! Don't get in the way while we're\n"
	.string "working!$"

Route123_EventScript_Davido_Text_1:
	.string "Well, someone who can handle a POKéMON\n"
	.string "battle can hang around.$"

Route123_EventScript_Davido_Text_2:
	.string "Sorry for startlin' you, we're just very\n"
	.string "anxious to get the job done on time.$"

Route123_EventScript_Caleb_Text_0:
	.string "Moving dirt is hard work. Battling is\n"
	.string "easier!$"

Route123_EventScript_Caleb_Text_1:
	.string "Maybe moving dirt is easier after all.$"

Route123_EventScript_Caleb_Text_2:
	.string "We're building the future of Hoenn here.\n"
	.string "I'm proud to be a part of it.$"

Route123_EventScript_Braxton_Text_0:
	.string "Let's battle while the boss is away.$"

Route123_EventScript_Braxton_Text_1:
	.string "Good fight!$"

Route123_EventScript_Braxton_Text_2:
	.string "We have a strong union, so the boss\n"
	.string "can't hassle us too much.$"

.global IJburg_MapScripts
IJburg_MapScripts::
	.byte 0

@ State descriptions for VAR_IJBURG_STATE
	@ 1: Got
	@ 2: Got Pokemon
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

IJburg_EventScript_GardenSign::
	msgbox IJburg_Text_GardenSign, MSGBOX_SIGN
	end

IJburg_EventScript_FrenkiesHouseSign::
	msgbox IJburg_Text_FrenkiesHouseSign, MSGBOX_SIGN
	end

IJburg_EventScript_IJburgSign::
	msgbox IJburg_Text_IJburgSign, MSGBOX_SIGN
	end

IJBURG_EventScript_NeedPokemonTrigger::
	lockall
	applymovement LOCALID_IJBURG_FAT_MAN, IJburg_Movement_Fat_ManApproachPlayerLeft
	waitmovement 0
	call IJburg_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_IJBURG_FAT_MAN, IJburg_Movement_Fat_ManReturnLeft
	waitmovement 0
	releaseall
	end

IJburg_EventScript_DangerousWithoutPokemon::
	msgbox IJburg_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_IJBURG_FAT_MAN, IJburg_Movement_Fat_ManPushPlayerFromRoute
	applymovement LOCALID_PLAYER, IJburg_Movement_PushPlayerBackFromRoute
	waitmovement 0
	msgbox IJburg_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
	closemessage
	return

IJburg_Movement_Fat_ManApproachPlayerLeft:
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	face_down
	step_end

IJburg_Movement_Fat_ManReturnLeft:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

IJburg_Movement_Fat_ManPushPlayerFromRoute:
	walk_down
	face_left
	step_end

IJburg_Movement_Man3_ApproachPlayerLeft:
	face_down
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	face_left
	step_end

IJburg_Movement_PushPlayerBackFromRoute10:
	lock_facing_direction
	walk_Up
	unlock_facing_direction
	step_end

IJburg_Movement_PushPlayerBackFromRoute:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

IJburg_EventScript_FAT_MAN::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, IJburg_EventScript_GoodLuck
	goto_if_set FLAG_RESCUED_BIRCH, IJburg_EventScript_YouSavedBirch
	msgbox IJburg_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	release
	end

IJburg_EventScript_GoodLuck::
	msgbox IJburg_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
	release
	end

IJburg_EventScript_YouSavedBirch::
	special GetPlayerBigGuyGirlString
	msgbox IJburg_Text_YouSavedBirch, MSGBOX_DEFAULT
	release
	end

IJburg_EventScript_GoSaveBirch::
	special GetPlayerBigGuyGirlString
	msgbox IJburg_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_IJBURG_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

IJBURG_EventScript_NeedPokemonTriggerRoute10::
	lockall
	applymovement LOCALID_MAN3, IJburg_Movement_Man3_ApproachPlayerLeft
	waitmovement 0
	msgbox IJburg_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, IJburg_Movement_PushPlayerBackFromRoute10
	applymovement LOCALID_MAN3, IJburg_Movement_Man3PushPlayerFromRoute
	waitmovement 0
	applymovement LOCALID_MAN3, IJburg_Movement_Man3_MoveBack
	closemessage
	return
	release
	end

IJburg_Movement_Man3PushPlayerFromRoute:
	walk_left
	face_up
	step_end

IJburg_Movement_Man3_MoveBack::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end


IJburg_Text_IfYouGoInGrassPokemonWillJumpOut:
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

IJburg_Text_YouSavedBirch:
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

IJburg_Text_GoodLuckCatchingPokemon:
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

IJburg_Text_DangerousIfYouDontHavePokemon:
	.string "Dude are you crazy?\p"
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

IJburg_Text_FrenkiesHouseSign:
	.string "Frenkies House.\l"
	.string "Give me rubbies, and enter!.$"

IJburg_Text_GardenSign:
	.string "Welcome to the Garden of IJburg.\l"
	.string "Only person's of extraordinary respect are allowed in.$"

IJburg_Text_IJburgSign:
	.string "IJburg\l"
	.string "Or Almere South South.$"

IJburg_Text_CanYouGoSeeWhatsHappening:
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

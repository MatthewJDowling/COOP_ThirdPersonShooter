// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SGameState.generated.h"


UENUM(BlueprintType)
enum class EWaveState : uint8
{

	WaitingToStart,


	PreparingNextWave,

	WaveInProgress,


	//No longer spawning bots, waiting for players to kill remaining bots
	WaitingToComplete,

	GameOver,

	WaveComplete,
};


/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API ASGameState : public AGameStateBase
{
	GENERATED_BODY()
	
protected:

	UFUNCTION()
	void OnRep_WaveState(EWaveState OldState);


	UFUNCTION(BlueprintImplementableEvent, Category = "Events")
	void WaveStateChanged(EWaveState NewState, EWaveState OldSstate);


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_WaveState, Category = "GameState")
	EWaveState WaveState;

public: 

	
	void SetWaveState(EWaveState NewState);


};

// Fill out your copyright notice in the Description page of Project Settings.

#include "SPowerUpActor.h"

// Sets default values
ASPowerUpActor::ASPowerUpActor()
{
	PowerUpInterval = 0.0f;
	TotalNrOfTicks = 0;

}

// Called when the game starts or when spawned
void ASPowerUpActor::BeginPlay()
{
	Super::BeginPlay();

}

void ASPowerUpActor::OnTickPowerup()
{
	TicksProcessed++;

	OnPowerUpTicked();


	if (TotalNrOfTicks >= TotalNrOfTicks)
	{
		OnExpired();


		GetWorldTimerManager().ClearTimer(TimerHandle_PowerupTick);
	}
}

void ASPowerUpActor::ActivatePowerup()
{
	if (PowerUpInterval > 0.0f)
	{
		GetWorldTimerManager().SetTimer(TimerHandle_PowerupTick, this, &ASPowerUpActor::OnTickPowerup, PowerUpInterval, true, 0.0f);

	}
	else
	{
		OnTickPowerup();
	}
}





// Fill out your copyright notice in the Description page of Project Settings.

#include "SPowerUpActor.h"
#include "TimerManager.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ASPowerUpActor::ASPowerUpActor()
{
	PowerUpInterval = 0.0f;
	TotalNrOfTicks = 0;

	bIsPowerupActive = false;

	SetReplicates(true);
}


void ASPowerUpActor::OnTickPowerup()
{
	TicksProcessed++;

	OnPowerUpTicked();


	if (TicksProcessed >= TotalNrOfTicks)
	{
		OnExpired();

		bIsPowerupActive = false;
		OnRep_PowerupActive();


		GetWorldTimerManager().ClearTimer(TimerHandle_PowerupTick);
	}
}

void ASPowerUpActor::OnRep_PowerupActive()
{

	OnPowerupStateChanged(bIsPowerupActive);

}

void ASPowerUpActor::ActivatePowerup()
{

	OnActivated();

	bIsPowerupActive = true;
	OnRep_PowerupActive();

	if (PowerUpInterval > 0.0f)
	{
		GetWorldTimerManager().SetTimer(TimerHandle_PowerupTick, this, &ASPowerUpActor::OnTickPowerup, PowerUpInterval, true);

	}
	else
	{
		OnTickPowerup();
	}
}

void ASPowerUpActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASPowerUpActor, bIsPowerupActive);


}





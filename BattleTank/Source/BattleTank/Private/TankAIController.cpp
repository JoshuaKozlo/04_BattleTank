// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank)) 
	{ 
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius os on cm

		// Aim towards the player
		ControlledTank->AimeAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); 
	}
	
}
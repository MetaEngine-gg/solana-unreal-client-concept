// Fill out your copyright notice in the Description page of Project Settings.


#include "ASolanaPawn.h"

// Sets default values
ASolanaPawn::ASolanaPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASolanaPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASolanaPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASolanaPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


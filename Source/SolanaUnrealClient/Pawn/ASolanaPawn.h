// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ASolanaPawn.generated.h"

UCLASS()
class SOLANAUNREALCLIENT_API ASolanaPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASolanaPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// HUD class to spawn for head up display
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMainHUD> MainHUD;

	// HUD instance
	UPROPERTY()
	class UMainHUD* MainHUDInstance;
};

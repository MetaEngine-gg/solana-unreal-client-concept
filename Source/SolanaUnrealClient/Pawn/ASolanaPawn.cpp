#include "ASolanaPawn.h"

ASolanaPawn::ASolanaPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASolanaPawn::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocallyControlled() && MainHUDClass)
	{
		MainHUDInstance = CreateWidget<UMainHUD>(GetWorld(), MainHUDClass);
		check(MainHUDInstance);
		MainHUDInstance->AddToPlayerScreen();
		MainHUDInstance->OnRunCommand.BindUObject(this, &ASolanaPawn::RunAPIRequest);
	}
}

void ASolanaPawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (MainHUDInstance)
	{
		MainHUDInstance->RemoveFromParent();
		// We can't destroy widget directly, because it will be destroyed by the GC
		MainHUDInstance = nullptr;
	}

	Super::EndPlay(EndPlayReason);
}

void ASolanaPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASolanaPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASolanaPawn::RunAPIRequest(const FString& Call)
{
	
}

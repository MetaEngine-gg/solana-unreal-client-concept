#include "ASolanaPawn.h"

ASolanaPawn::ASolanaPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASolanaPawn::BeginPlay()
{
	Super::BeginPlay();

	M_BackendServiceInstance = GetWorld()->SpawnActor<ABackendService>();
	
	if (IsLocallyControlled() && MainHUDClass)
	{
		M_MainHUDInstance = CreateWidget<UMainHUD>(GetWorld(), MainHUDClass);
		check(M_MainHUDInstance);
		M_MainHUDInstance->Init();
		M_MainHUDInstance->AddToPlayerScreen();

		M_MainHUDInstance->OnRunCommand.BindUObject(this, &ASolanaPawn::RunAPIRequest);
		M_BackendServiceInstance->OnRequestComplete.BindUObject(this, &ASolanaPawn::OnRequestFinished);
	}
}

void ASolanaPawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (M_MainHUDInstance)
	{
		M_MainHUDInstance->RemoveFromParent();
		// We can't destroy widget directly, because it will be destroyed by the GC
		M_MainHUDInstance = nullptr;
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

void ASolanaPawn::RunAPIRequest(const FString Call) const
{
	M_BackendServiceInstance->SendGetRequest(Call);
}

void ASolanaPawn::OnRequestFinished(const FString Output) const
{
	M_MainHUDInstance->ClearOutputText();
	M_MainHUDInstance->SetOutputText(Output);
}

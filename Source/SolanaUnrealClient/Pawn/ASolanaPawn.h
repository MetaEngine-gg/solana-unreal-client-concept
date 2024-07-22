#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SolanaUnrealClient/HUD/UMainHUD.h"
#include "ASolanaPawn.generated.h"

UCLASS()
class SOLANAUNREALCLIENT_API ASolanaPawn : public APawn
{
	GENERATED_BODY()

public:
	ASolanaPawn();

protected:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// HUD class to spawn for head up display
	UPROPERTY(EditAnywhere)
	TSubclassOf<UMainHUD> MainHUDClass = nullptr;

	// HUD instance
	UPROPERTY()
	UMainHUD* MainHUDInstance = nullptr;

	void RunAPIRequest(const FString& Call);
};

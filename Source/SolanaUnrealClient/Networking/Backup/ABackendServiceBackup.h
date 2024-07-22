#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "ABackendService.generated.h"

UCLASS()
class SOLANAUNREALCLIENT_API ABackendServiceBackup : public AActor
{
	GENERATED_BODY()

public:
	ABackendServiceBackup();

	void SendGetRequest(const FString& Url);
	void HandleResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

protected:
	void TimerElapsed();
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	TSharedPtr<IHttpRequest> M_HttpRequest;
	bool M_IsRequestComplete = true;
	FString M_CallStack[3];
	int M_CallStackIndex = 0;
	const int M_CallStackCount = 3;
	FTimerHandle TimerHandle;
};

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "ABackendService.generated.h"

DECLARE_DELEGATE_OneParam(FOnRequestComplete, const FString& /*Request*/);

UCLASS()
class SOLANAUNREALCLIENT_API ABackendService : public AActor
{
	GENERATED_BODY()

public:
	ABackendService();

	void SendGetRequest(const FString& Url);
	void HandleResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	FOnRequestComplete OnRequestComplete;

private:
	TSharedPtr<IHttpRequest> M_HttpRequest;
	bool M_IsRequestComplete = true;
};

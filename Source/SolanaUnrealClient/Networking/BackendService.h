#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnRequestComplete);

class SOLANAUNREALCLIENT_API BackendService
{
public:
	BackendService();

	void SendGetRequest(const FString& Url);
	void HandleResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

public:
	FOnRequestComplete OnRequestComplete;

private:
	TSharedPtr<IHttpRequest> M_HttpRequest;
	bool M_IsRequestComplete = true;
};

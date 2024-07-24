#include "ABackendService.h"

#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"

ABackendService::ABackendService()
{
}

void ABackendService::SendGetRequest(const FString Url)
{
	if (M_IsRequestComplete == false)
	{
		UE_LOG(LogTemp, Error, TEXT("Request is already in progress"));
		OnRequestComplete.Execute(TEXT("Request is already in progress"));
		return;
	}
	
	if (Url.IsEmpty() || !Url.Contains("http://") && !Url.Contains("https://"))
	{
		UE_LOG(LogTemp, Error, TEXT("Url is invalid"));
		OnRequestComplete.Execute(TEXT("Url is invalid"));
		return;
	}
	
	M_IsRequestComplete = false;
	M_HttpRequest = FHttpModule::Get().CreateRequest();
	M_HttpRequest->OnProcessRequestComplete().BindUObject(this, &ABackendService::HandleResponse);
	M_HttpRequest->SetURL(Url);
	M_HttpRequest->SetVerb("GET");
	M_HttpRequest->ProcessRequest();
}

void ABackendService::HandleResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	FString ResponseStr;
	if (bWasSuccessful && Response.IsValid())
	{
		ResponseStr = "[RESPONSE] " + Response->GetContentAsString();
	}
	else
	{
		ResponseStr = "[FAIL] Response is empty";
	}

	M_IsRequestComplete = true;
	OnRequestComplete.Execute(ResponseStr);
}

void ABackendService::BeginPlay()
{
	Super::BeginPlay();
}

void ABackendService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


#include "BackendService.h"

#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"

BackendService::BackendService()
{
}

void BackendService::SendGetRequest(const FString& Url)
{
	M_IsRequestComplete = false;
	M_HttpRequest = FHttpModule::Get().CreateRequest();
	M_HttpRequest->OnProcessRequestComplete().BindUObject(this, &BackendService::HandleResponse);
	M_HttpRequest->SetURL(Url);
	M_HttpRequest->SetVerb("GET");
	M_HttpRequest->ProcessRequest();
}

void BackendService::HandleResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful && Response.IsValid())
	{
		const FString ResponseStr = Response->GetContentAsString();
		UE_LOG(LogTemp, Warning, TEXT("Response: %s"), *ResponseStr);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Request failed"));
	}

	M_IsRequestComplete = true;
}


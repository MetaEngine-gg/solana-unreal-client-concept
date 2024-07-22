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
	FString ResponseStr;
	if (bWasSuccessful && Response.IsValid())
	{
		ResponseStr = "[SUCCESS]" + Response->GetContentAsString();
	}
	else
	{
		ResponseStr = "[FAIL]" + Response->GetContentAsString();
	}

	M_IsRequestComplete = true;
	OnRequestComplete.Broadcast(ResponseStr);
}


#include "ABackendServiceBackup.h"

#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"

ABackendServiceBackup::ABackendServiceBackup()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABackendServiceBackup::SendGetRequest(const FString& Url)
{
	M_IsRequestComplete = false;
	M_HttpRequest = FHttpModule::Get().CreateRequest();
	M_HttpRequest->OnProcessRequestComplete().BindUObject(this, &ABackendServiceBackup::HandleResponse);
	M_HttpRequest->SetURL(Url);
	M_HttpRequest->SetVerb("GET");
	M_HttpRequest->ProcessRequest();
}

void ABackendServiceBackup::HandleResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

void ABackendServiceBackup::TimerElapsed()
{
	if (M_CallStackIndex >= M_CallStackCount)
	{
		GetWorldTimerManager().ClearTimer(TimerHandle);
		return;
	}
	
	SendGetRequest(M_CallStack[M_CallStackIndex]);
	M_CallStackIndex++;
}

void ABackendServiceBackup::BeginPlay()
{
	Super::BeginPlay();

	const FString BaseAPICall = "https://localhost:7035/api/solana/";
	FString const Address = "5nJJRrGB8MqyZ5bBoF32HsdWuzzLSEX5UJG6EMqu432T";

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABackendServiceBackup::TimerElapsed, 1.0f, true);

	M_CallStack[0] = BaseAPICall + "balance/" + Address;
	M_CallStack[1] = BaseAPICall + "airdrop/" + Address;
	M_CallStack[2] = BaseAPICall + "balance/" + Address;
}

void ABackendServiceBackup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


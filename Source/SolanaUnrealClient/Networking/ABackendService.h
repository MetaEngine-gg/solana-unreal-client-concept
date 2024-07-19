// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "ABackendService.generated.h"

UCLASS()
class SOLANAUNREALCLIENT_API ABackendService : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABackendService();

	// Function to send a GET request
	void SendGetRequest(const FString& Url);
	// Function to handle the HTTP response
	void HandleResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

protected:
	void TimerElapsed();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	TSharedPtr<IHttpRequest> M_HttpRequest;
	bool M_IsRequestComplete = true;
	FString M_CallStack[3];
	int M_CallStackIndex = 0;
	const int M_CallStackCount = 3;
	FTimerHandle TimerHandle;
};

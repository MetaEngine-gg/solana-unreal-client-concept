<p align="center">
    <img src="https://raw.githubusercontent.com/bmresearch/Solnet/master/assets/icon.png" margin="auto" height="175"/>
</p>

<div style="text-align:center">

<p>

# Introduction

SOL.BRIDGE.CLIENT is a simple Unreal Engine 5 project that demonstrates how to interact with the SOL.BRIDGE server-side application using REST API calls. It's a good starting point for anyone who wants to build a client-side application that interacts with a SOL.BRIDGE server.

</p>

</div>

## Features
- Implements a simple client-side application that interacts with the SOL.BRIDGE server-side application.
- Have simple UI that allows you to interact with the server-side application by making REST API calls from the UMG Widget.
- Have C++ classes that demonstrate how to make REST API calls using Unreal Engine 5.
- Shows how to handle responses and errors from the server-side application.
- Serialize and deserialize data examples using C++.
- Clear flow how to handle HTTP/HTTPS requests using Unreal Engine 5 and C++ static delegates.

## Getting Started

- Clone the repository.
- Open the project in Unreal Engine 5.
- Run the project.
- You can interact with the server-side application by using the UI in the UMG Widget.
- Put API address to the input field and press the send button to make a REST API call.
- You can see the response in the output block below.

## Solution Structure Overview

### HUD

- Classes that control UMG Widgets and handle user input.
- Contains main UI logic and callbacks that are triggered by user input.
- Callbacks from the UI then goes to the different classes that handle the logic.

#### UMainHUD.h:

```c++
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/TextBlock.h"
#include "UMainHUD.generated.h"

DECLARE_DELEGATE_OneParam(FRunCommandDelegate, const FString /*Call*/);

UCLASS()
class SOLANAUNREALCLIENT_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	void Init() const;

	UFUNCTION()
	void RunCommand();
	UFUNCTION()
	void ClearOutputText();
	void AddOutputText(const FString& String);
	
	FRunCommandDelegate OnRunCommand;
private:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UEditableText* BaseApiText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* RunButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* ClearButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* OutputText;
};
```

### Networking

- This is where all networking logic is located.
- Contains classes that handle HTTP/HTTPS requests and responses.
- Handles serialization and deserialization of data.
- Responsible for making REST API calls to the server-side application.

#### ABackendService.h:

```c++
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "ABackendService.generated.h"

DECLARE_DELEGATE_OneParam(FOnRequestComplete, const FString /*Request*/);

UCLASS()
class SOLANAUNREALCLIENT_API ABackendService : public AActor
{
	GENERATED_BODY()

public:
	ABackendService();

	void SendGetRequest(const FString Url);
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
```

### Pawn

- Just a simple Pawn class that is used to spawn the HUD.
- Responsible for creating the HUD and setting up the UI.
- Redirects delegates from the HUD to the BackendService.

#### ASolanaPawn.h:

```c++
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SolanaUnrealClient/HUD/UMainHUD.h"
#include "SolanaUnrealClient/Networking/ABackendService.h"
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
	void RunAPIRequest(const FString Call) const;
	void OnRequestFinished(const FString Output) const;

private:
	// HUD class to spawn for head up display
	UPROPERTY(EditAnywhere)
	TSubclassOf<UMainHUD> MainHUDClass = nullptr;

	// HUD instance
	UPROPERTY()
	UMainHUD* M_MainHUDInstance = nullptr;

	ABackendService* M_BackendServiceInstance = nullptr;
};
```

## Solnet Library

Consider checking out the [Solnet](https://github.com/bmresearch/Solnet) library for more information on how to interact with Solana blockchain.
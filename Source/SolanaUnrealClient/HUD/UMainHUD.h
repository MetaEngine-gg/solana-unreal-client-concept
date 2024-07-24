#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/TextBlock.h"
#include "UMainHUD.generated.h"

DECLARE_DELEGATE_OneParam(FRunCommandDelegate, const FString& /*Call*/);

UCLASS()
class SOLANAUNREALCLIENT_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	void RunCommand();
	void ClearOutputText();
	void SetOutputText(const FString& String);

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UEditableText* BaseApiText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UEditableText* AddressText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* RunButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* OutputText;

	FRunCommandDelegate OnRunCommand;
};

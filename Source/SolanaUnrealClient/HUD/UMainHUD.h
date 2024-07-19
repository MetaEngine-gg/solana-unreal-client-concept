#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/TextBlock.h"
#include "UMainHUD.generated.h"

UCLASS()
class SOLANAUNREALCLIENT_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	void RunCommand();

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UEditableText* BaseApiText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UEditableText* AddressText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* RunButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* OutputText;
};

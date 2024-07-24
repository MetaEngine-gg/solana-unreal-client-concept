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
	void ClearOutputText() const;
	void AddOutputText(const FString& String);
	
	FRunCommandDelegate OnRunCommand;
private:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UEditableText* BaseApiText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* RunButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* OutputText;

	uint32_t TextStackSize = 0;
};

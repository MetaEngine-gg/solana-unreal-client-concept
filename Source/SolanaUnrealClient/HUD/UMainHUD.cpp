#include "UMainHUD.h"

void UMainHUD::Init() const
{
	RunButton->OnClicked.AddDynamic(this, &UMainHUD::RunCommand);
}

void UMainHUD::RunCommand()
{
	FString Call = BaseApiText->GetText().ToString();
	OnRunCommand.Execute(Call);
}

void UMainHUD::ClearOutputText() const
{
	OutputText->SetText(FText::FromString(""));
}

void UMainHUD::AddOutputText(const FString& String)
{
	if (TextStackSize > 10)
	{
		ClearOutputText();
		TextStackSize = 0;
	}

	const FString NewText = OutputText->GetText().ToString() + "\n" + String;
	OutputText->SetText(FText::FromString(NewText));
	TextStackSize++;
}

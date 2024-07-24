#include "UMainHUD.h"

void UMainHUD::Init() const
{
	RunButton->OnClicked.AddDynamic(this, &UMainHUD::RunCommand);
	ClearButton->OnClicked.AddDynamic(this, &UMainHUD::ClearOutputText);
}

void UMainHUD::RunCommand()
{
	FString Call = BaseApiText->GetText().ToString();
	OnRunCommand.Execute(Call);
}

void UMainHUD::ClearOutputText()
{
	OutputText->SetText(FText::FromString(""));
}

void UMainHUD::AddOutputText(const FString& String)
{
	const FString NewText = OutputText->GetText().ToString() + "\n" + String;
	OutputText->SetText(FText::FromString(NewText));
}

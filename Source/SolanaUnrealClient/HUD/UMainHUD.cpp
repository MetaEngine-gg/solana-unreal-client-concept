#include "UMainHUD.h"

void UMainHUD::Init() const
{
	RunButton->OnClicked.AddDynamic(this, &UMainHUD::RunCommand);
}

void UMainHUD::RunCommand()
{
	FString Call = BaseApiText->GetText().ToString() + AddressText->GetText().ToString();
	OnRunCommand.Execute(Call);
}

void UMainHUD::ClearOutputText() const
{
	OutputText->SetText(FText::FromString(""));
}

void UMainHUD::SetOutputText(const FString& String) const
{
	OutputText->SetText(FText::FromString(String));
}

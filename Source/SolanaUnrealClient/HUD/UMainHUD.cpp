#include "UMainHUD.h"

void UMainHUD::RunCommand() const
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

#include "UMainHUD.h"

void UMainHUD::RunCommand()
{
	FString Call = BaseApiText->GetText().ToString() + AddressText->GetText().ToString();
	OnRunCommand.Execute(Call);
}

void UMainHUD::ClearOutputText()
{
	OutputText->SetText(FText::FromString(""));
}

void UMainHUD::SetOutputText(const FString& String)
{
	OutputText->SetText(FText::FromString(String));
}

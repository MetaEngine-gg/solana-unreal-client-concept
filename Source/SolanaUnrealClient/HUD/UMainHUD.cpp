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

void UMainHUD::AddOutputText(const FString& String)
{
	OutputText->SetText(FText::FromString(String));
	TextStackSize++;

	if (TextStackSize > 10)
	{
		ClearOutputText();
		TextStackSize = 0;
	}
}

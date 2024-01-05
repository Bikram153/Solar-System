#include "MyTextWidget.h"
#include "Components/TextBlock.h"

void UMyTextWidget::NativeConstruct()
{
    Super::NativeConstruct();
}

void UMyTextWidget::SetMessage(const FText& Message, const FText& Message1, const FText& Message2, const FText& Message3)
{
    if (TextBlockWidget)
    {
        TextBlockWidget->SetText(Message);
    }
    if (m)
    {
        m->SetText(Message1);
    }
    if (v)
    {
        v->SetText(Message2);
    }
    if (d)
    {
        d->SetText(Message3);
    }
}


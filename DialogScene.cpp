#include "DXUT.h"
#include "DialogScene.h"

void DialogScene::Init()
{
	dialog = new Dialog();
	char str[256];
	sprintf(str, "stage%d", type);
	dialog->go_scene = str;
	switch (type)
	{
	case 1:
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("����� ��������, ������ �鸮�ʴϱ�!!"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("����.. ���� ���� ������ �ƹ��͵� ����� �ȳ��±�", "����� ��Ʈ N1-3��ü, �鸰��"));
		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("��� ���߻��� ���� �κ������� ����� ���� �� ����"));

		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("�������ʴϱ�? ���� �ȴ�ġ�̽��ϱ�?"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("���� ��ó ����� ������", "���� ��Ȳ �� ª�� �������� �� �ֳ�?"));

		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("�� �˰ڽ��ϴ�", "���� ����Ư����� ��Ʈ �Ҽ� �������� ��� �����Դϴ�"));
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("���� ���� �ӹ��� ������ ���⸦ ��� ���İ�", "'Ʈ��������' �� �������� �����ϴ� ���Դϴ�"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("���� ����, Ȥ�� �� ��ü�� �������� �� �ֳ�?", "��� ����̰� �Ǽ� ���̾�"));
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("��, �ٷ� �����帮�ڽ��ϴ�"));
		break;
	case 2:
		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("����, ���� ��Ȳ �����߾�"));

		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("�����ϼ̽��ϴ�, ���� �� ���縦 �غôµ�,", "'Ʈ��������' �� �ܼ� �׷������� �ƴ�", "���̺������� �� �����ϴ�"));
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("���� ������ Ʈ�����ʹ� ����� �Ƶ��̾���,", "���� �̸����� 2068�⿡ Ż�� �� ������", "������ �ֽ��ϴ�"));
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("��ġ�� �ִ� ����� ���ϰ�, �׷����� �� ���� �񱳸� ����", "�������� ���� �̷� ���� ���� ������ ���Դϴ�"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("�׷��� ��� �Ͽ��� ������ �ִ� ������"));

		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("��� 'Ʈ��������' �� �������� �˾Ƴ½��ϴ�", "�׸��� �������ѵ帮�ڽ��ϴ�", "����� ���ϴ�"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("����"));
		break;
	case 3:
		dialog->chat_types.emplace_back(ChatType::ME2TRICKSTER);
		dialog->scripts.emplace_back(Script("���� �������� �׷��� ������ ö���̱�"));

		dialog->chat_types.emplace_back(ChatType::TRICKSTER2ME);
		dialog->scripts.emplace_back(Script("��.. ���̷��°ž�!! �� ���� ����� �����Ŷ��!", "�Ų��� ���⸦ ��ġ�� �������ֽŴ��!! ���� ����ٰ�!"));

		dialog->chat_types.emplace_back(ChatType::ME2TRICKSTER);
		dialog->scripts.emplace_back(Script("������ ���ұ�", "Ʈ������, �����̶� �յ�� �����ض�"));

		dialog->chat_types.emplace_back(ChatType::TRICKSTER2ME);
		dialog->scripts.emplace_back(Script("�����̶�� ���� �����ҰͰ���?!"));

		dialog->chat_types.emplace_back(ChatType::ME2TRICKSTER);
		dialog->scripts.emplace_back(Script("����, ������ ����"));
		break;
	case 4:
		dialog->go_scene = "clear";

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("����, Ʈ������ ���п� �����ߴ�"));

		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("�����ϼ̽��ϴ� ������"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("�׷� �ް������� ���̶� ��ڳ�", "�׶� �ٽ� ������"));
		break;
	}

	//dialog->chater1.pos = V2(CENTER.x - 300, CENTER.y - 100);
	//dialog->chater2.pos = V2(CENTER.x + 300, CENTER.y - 100);

	OBJ->Add(dialog, "dialog")->pos = CENTER;
}

void DialogScene::Update()
{
}

void DialogScene::Render()
{
}

void DialogScene::Release()
{
}

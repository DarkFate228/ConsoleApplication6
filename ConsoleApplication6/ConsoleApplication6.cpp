#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>

void button_callBack(Fl_Widget* widget, void* data) {
	Fl_Input* input = static_cast<Fl_Input*>(data);

	const char* text = input->value();

	Fl_Output* output = static_cast<Fl_Output*>(widget->parent()->child(2));
	output->value(text);
}

int main() {
	Fl_Window* window = new Fl_Window(400, 200, u8"Простой ввод-вывод");
	Fl_Input* input = new Fl_Input(100, 40, 200, 30, u8"Введите текст");
	Fl_Button* button = new Fl_Button(150, 90, 100, 30, u8"вывести текст");
	button->callback(button_callBack, input);
	Fl_Output* output = new Fl_Output(100, 140, 200, 30, u8"Результат");
	window->end();
	window->show();
	return Fl::run();
}
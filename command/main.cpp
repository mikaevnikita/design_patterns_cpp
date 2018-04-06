#include <iostream>
#include <stack>
using namespace std;

/*
Паттерн Команда(Action, Действие, Транзакция, Command) -
- Убирает прямую зависимость между объектами, вызывающими операции и объектами, которые их непосредственно выполняют.
+превращает запросы в объекты, позволяя передавать их как аргументы при вызове методов
+позволяет ставить запросы в очередь
+позволяет логировать запросы
+поддержка отмены операций
+поддержка транзакций
+позволяет реализовать отложенный запуск операций
+позволяет собирать сложные команды из простых.

Классическая схема состоит из 4 объектов:
Клиент
Инициатор(Инвокер)
Получатель
Команда

В данной реализации Editor - Получатель, Command - Команда, Applicaton - Инициатор, Клиент
Возможна ситуация с "умными" командами реализующими в себе всю бизнес логику
*/

class Editor{
private:
    string text;
public:
    void setText(string new_text){
        text = new_text;
    }

    string getText(){
        return text;
    }

    string getSelection(){
        return "Return selected text";
    }

    void deleteSelection(){
        cout << "Delete selected text" << endl;
    }

    void replaceSelection(string text){
        cout << "Text was replaced" << endl;
        this->text = text;
    }
};

class Application;

class Command{
protected:
    Application* app;
    Editor* editor;
    string backup_text;
public:
    Command(Application* app, Editor* editor);

    void saveBackup();

    virtual void undo() = 0;
    virtual void execute() = 0;
};

class CommandHistory{
private:
    stack<Command*> history;
public:
    void push(Command* command){
        history.push(command);
    }

    Command* pop(){
        if(history.empty())
            return nullptr;
        Command* command = history.top();
        history.pop();
        return command;
    }
};

class Application{
private:
    Editor* editor;
    CommandHistory history;
    string clipboard;
public:
    Application(Editor* editor){
        this->editor = editor;
    }

    string getClipboard(){
        return clipboard;
    }

    void setClipboard(string new_clipboard){
        clipboard = new_clipboard;
    }

    void executeCommand(Command* command){
        history.push(command);
        command->execute();
    }

    void undo(){
        Command* command = history.pop();
        if (command != nullptr)
            command->undo();
    }
};


Command::Command(Application* app, Editor* editor){
    this->app = app;
    this->editor = editor;
}


void Command::saveBackup(){
    backup_text = editor->getText();
}

class CopyCommand: public Command{
public:
    CopyCommand(Application* app, Editor* editor)
        :Command(app, editor){}
    void execute(){
        app->setClipboard(editor->getSelection());
    }
    void undo(){

    }
};

class CutCommand: public Command{
public:
    CutCommand(Application* app, Editor* editor)
        :Command(app, editor){}
    void execute(){
        saveBackup();
        app->setClipboard(editor->getSelection());
        editor->deleteSelection();
    }
    void undo(){
        editor->setText(backup_text);
    }
};

class PasteCommand: public Command{
public:
    PasteCommand(Application* app, Editor* editor)
        :Command(app, editor){}
    void execute(){
        saveBackup();
        editor->replaceSelection(app->getClipboard());
    }
    void undo(){
        editor->setText(backup_text);
    }
};

class UndoCommand: public Command{
public:
    UndoCommand(Application* app, Editor* editor)
        :Command(app, editor){}
    void execute(){
        app->undo();
    }
    void undo(){

    }
};


int main()
{
    Editor* editor = new Editor;
    editor->setText("Default text");
    Application app(editor);

    Command* command = new CopyCommand(&app, editor);
    app.executeCommand(command);

    cout << app.getClipboard() << endl;//Return selected text in app.clipboard
    delete command;

    command = new PasteCommand(&app, editor);
    app.setClipboard("change buffer text");
    app.executeCommand(command);
    cout << editor->getText() << endl;//change buffer text
    app.undo();
    cout << editor->getText() << endl;//Return selected text

    return 0;
}

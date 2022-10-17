#include "calculator.h"
#include <assert.h>

Calculator::Calculator(std::set<Language> language_set,
                       std::vector<std::string> param_sentence)
    : language_set_(language_set), sentence_(param_sentence) {}

Calculator::~Calculator() {}

Language Calculator::GetResult() {
  for (size_t i = 0; i < sentence_.size(); i++) {
    if (isLanguage(sentence_.at(i))) {
      stack_.push(GetLanguage(sentence_.at(i)));
    } else {
      switch ((char)sentence_.at(i).at(0)) {
      case '+': {
        Language l2(stack_.top());
        stack_.pop();
        Language l1(stack_.top());
        stack_.pop();
        stack_.push(l1.Concatenation_L(l2));
        break;
      }
      case '|': {
        Language l2(stack_.top());
        stack_.pop();
        Language l1(stack_.top());
        stack_.pop();
        stack_.push(l1.Union(l2));
        break;
      }
      case '^': {
        Language l2(stack_.top());
        stack_.pop();
        Language l1(stack_.top());
        stack_.pop();
        Language lan_aux(l1.Intersection(l2));
        stack_.push(l1.Intersection(l2));
        break;
      }
      case '-': {
        Language l2(stack_.top());
        stack_.pop();
        Language l1(stack_.top());
        stack_.pop();
        stack_.push(l1.Diference(l2));
        break;
      }
      case '!': {
        Language l1(stack_.top());
        stack_.pop();
        stack_.push(l1.Reverse());
        break;
      }
      case '*': {
        Language l1(stack_.top());
        stack_.pop();
        stack_.push(l1.Power(stoi(sentence_.at(i - 1))));
        break;
      }
      default:
        break;
      }
    }
  }
  if (stack_.size() == 1) {
    Language lang_aux(stack_.top(), "L_result");
    return lang_aux;
  }
  assert(stack_.size() == 1);
}

Language Calculator::GetLanguage(std::string param_lang_id) {
  for (std::set<Language>::iterator it = language_set_.begin();
       it != language_set_.end(); ++it) {
    if (param_lang_id == it->GetNameID()) {
      return *it;
    }
  }
  //
}

bool Calculator::isLanguage(std::string param_name) {
  for (std::set<Language>::iterator it = language_set_.begin();
       it != language_set_.end(); ++it) {
    if (param_name == it->GetNameID()) {
      return true;
    }
  }
  return false;
}
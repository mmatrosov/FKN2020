class NotifierBase {
public:
    virtual void Notify(const std::string& str) const = 0;
};

class SmsNotifier: public NotifierBase {
private:
    std::string number;
public:
    SmsNotifier(const std::string& num) : number(num) {}

    void Notify(const std::string& text) const {
        SendSms(number, text);
    }
};

class EmailNotifier: public NotifierBase {
private:
    std::string email;
public:
    EmailNotifier(const std::string& adr) : email(adr) {}

    void Notify(const std::string& text) const {
        SendEmail(email, text);
    }
};
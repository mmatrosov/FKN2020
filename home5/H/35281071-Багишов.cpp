class NotifierBase {
public:
    virtual void Notify(std::string const&) const = 0;
};

class SmsNotifier : public NotifierBase {
    std::string telephone;

public:
    SmsNotifier(std::string const& _t) : telephone(_t) {
    }

    void Notify(std::string const& message) const override {
        SendSms(telephone, message);
    }
};
class EmailNotifier : public NotifierBase {
    std::string email;

public:
    EmailNotifier(std::string const& _e) : email(_e) {
    }
    void Notify(std::string const& message) const override {
        SendEmail(email, message);
    }
};
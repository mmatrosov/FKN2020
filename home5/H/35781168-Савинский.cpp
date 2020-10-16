class NotifierBase {
   public:
    std::string address;

    NotifierBase(const std::string& _address) : address(_address) {
    }

    virtual void Notify(const std::string&) const = 0;
};

class SmsNotifier : public NotifierBase {
   public:
    SmsNotifier(const std::string& number) : NotifierBase(number) {
    }

    void Notify(const std::string& str) const {
        SendSms(address, str);
    }
};

class EmailNotifier : public NotifierBase {
   public:
    EmailNotifier(const std::string& email) : NotifierBase(email) {
    }

    void Notify(const std::string& str) const {
        SendEmail(address, str);
    }
};

/*
Notification Service -
i) plug and play model - which means, we can integrate this in many other applications with minimal code changes
ii) extendible - can be easily extended to whatsapp, email, sms, pop-up and other platforms
iii) dynamically extendible - we can add headers, footers, signatures, timestamp to it.
iv) store and log all notifications

=> notification engine (abstract) - further concrete classes of it, will decide how to send notifications over the mail, sms and other kinds over the internet
it has a bunch of strategies that decides how to send the notification, in what media.
NotificationEngine one to many 'has-a' NotificationStrategy

=> notification observable - it only tells whenever a notification comes, it doesn't care about how it will be transmitted
setNotification() -> notify() -> update()
*/
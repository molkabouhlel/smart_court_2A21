from twilio.rest import Client
import sys

# Your Account SID from twilio.com/console
account_sid = "AC1799f84c311b0cc8b9643c34a7752fa7"
# Your Auth Token from twilio.com/console
auth_token  = "d3d76bd76ba8731d3e62c31be8710dba"

client = Client(account_sid, auth_token)

message = client.messages.create(
    #to="+21626560442",
    to=sys.argv[1],

    from_="+18646356081",
    body="your order is ready!")

print(message.sid)

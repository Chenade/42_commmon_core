sudo apt-get update
sudo apt -y install apt-transport-https ca-certificates curl gnupg2 software-properties-common
curl -fsSL https://download.docker.com/linux/debian/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg
sudo apt update
sudo apt install -y docker-ce docker-ce-cli containerd.io
sudo apt-get install docker-compose
sudo chmod 666 /var/run/docker.sock

sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

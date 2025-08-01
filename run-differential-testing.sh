#!/bin/bash

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Check if Docker is installed
check_docker() {
    if ! command -v docker &> /dev/null; then
        print_error "Docker is not installed. Please install Docker first."
        exit 1
    fi
    
    if ! command -v docker-compose &> /dev/null; then
        print_error "Docker Compose is not installed. Please install Docker Compose first."
        exit 1
    fi
    
    print_success "Docker and Docker Compose are installed"
}

# Create necessary directories
setup_directories() {
    print_status "Creating necessary directories..."
    mkdir -p results logs custom-seeds
    print_success "Directories created"
}

# Build the Docker image
build_image() {
    print_status "Building Docker image..."
    docker-compose build
    print_success "Docker image built successfully"
}

# Start the container
start_container() {
    print_status "Starting differential testing container..."
    docker-compose up -d
    print_success "Container started successfully"
}

# Show logs
show_logs() {
    print_status "Showing container logs..."
    docker-compose logs -f
}

# Stop the container
stop_container() {
    print_status "Stopping container..."
    docker-compose down
    print_success "Container stopped"
}

# Check container status
check_status() {
    print_status "Checking container status..."
    docker-compose ps
}

# Show results
show_results() {
    print_status "Differential testing results:"
    if [ -d "results/differential_finding_folder_javascript" ]; then
        echo "Found $(find results/differential_finding_folder_javascript -type f | wc -l) differential findings"
        ls -la results/differential_finding_folder_javascript/
    else
        print_warning "No results directory found yet"
    fi
}

# Main script logic
case "${1:-help}" in
    "setup")
        print_status "Setting up differential testing environment..."
        check_docker
        setup_directories
        build_image
        print_success "Setup completed successfully!"
        ;;
    "start")
        print_status "Starting differential testing..."
        start_container
        print_success "Differential testing started!"
        print_status "Use './run-differential-testing.sh logs' to view logs"
        ;;
    "logs")
        show_logs
        ;;
    "stop")
        stop_container
        ;;
    "status")
        check_status
        ;;
    "results")
        show_results
        ;;
    "restart")
        print_status "Restarting container..."
        stop_container
        start_container
        print_success "Container restarted!"
        ;;
    "clean")
        print_warning "This will remove all containers and images. Are you sure? (y/N)"
        read -r response
        if [[ "$response" =~ ^([yY][eE][sS]|[yY])$ ]]; then
            print_status "Cleaning up..."
            docker-compose down --rmi all --volumes --remove-orphans
            rm -rf results logs
            print_success "Cleanup completed!"
        else
            print_status "Cleanup cancelled"
        fi
        ;;
    "help"|*)
        echo "Perses Differential Testing Helper Script"
        echo ""
        echo "Usage: $0 [command]"
        echo ""
        echo "Commands:"
        echo "  setup    - Set up the environment (check Docker, create dirs, build image)"
        echo "  start    - Start the differential testing container"
        echo "  logs     - Show container logs"
        echo "  stop     - Stop the container"
        echo "  status   - Check container status"
        echo "  results  - Show differential testing results"
        echo "  restart  - Restart the container"
        echo "  clean    - Remove all containers, images, and data"
        echo "  help     - Show this help message"
        echo ""
        echo "Example workflow:"
        echo "  $0 setup    # First time setup"
        echo "  $0 start    # Start testing"
        echo "  $0 logs     # Monitor progress"
        echo "  $0 results  # Check results"
        echo "  $0 stop     # Stop when done"
        ;;
esac 